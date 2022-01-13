#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

//а) інформацію про всі вистави заданого режисера;
//б) інформацію про вистави, які тривають в заданий момент часу;

void fillFile (const char *fname);
int fillBuff(char buff[20][100], const char *fname);
void displayChar (char buff[20][100], int size);
void checkTime (char buff[20][100], int size);
void findAuthor (char buff[20][100], int size);
void add (const char*fname);
void menu (const char*fname,char buff[20][100], int size);



int main(){
    const char* fname = "/Users/alinarybina/Desktop/Уник/АПр/ЛБ/АПрЛБ4/АПрЛБ4/textfile.txt";
    fillFile(fname);
    char buff[20][100];
    int size = fillBuff(buff, fname);
    menu (fname, buff, size);
return 0;
}

void fillFile (const char *fname){
    ofstream fout;
    fout.open (fname, ios:: binary);
    if (!fout) {
        cout << "Ошибка открытия файла"; return;
    }
    fout<<"Мастер и Маргарита, фантастика, Семенов, 18:00, 2:30, 5 ,127.44;Свадьба Фигаро, комедия, Моцарт, 18:30, 1:30, 3, 247.91;Балет Дюймовочка, драма, Васюткин, 13:00, 1:00, 8, 635.76;";
    fout.close();
}

int fillBuff(char buff[20][100], const char *fname){
    ifstream fin;
    fin.open (fname, ios :: binary);
    int size = 0;
    while (fin.getline(buff[size], 100, ';')){
        size++;
    }
    fin.close();
    return size;
}


void displayChar (char buff[20][100], int size){
    for (int i = 0; i < size; i++){
        cout<<buff[i]<<endl;
    }
}

void checkTime (char buff[20][100], int size){
    char help[size][5];
    int index = 0;
    for (int i = 0; i < size; i++){
        index = strcspn (buff[i], ":");
        help [i][0] = buff[i][index - 2];
        help [i][1] = buff[i][index - 1];
        help [i][2] = buff[i][index + 1];
        help [i][3] = buff[i][index + 2];
        help [i][4] = '\0';
    }
    int numberHelp[size][3];
    for (int i = 0; i < size; i++){
        numberHelp[i][0] = atoi(help[i]);
        numberHelp[i][0] = numberHelp[i][0]%100 + numberHelp[i][0]/100*60;
    }
    for (int i = 0; i < size; i++){
        index = strcspn (buff[i], ":");
        help [i][0] = buff[i][index + 5];
        help [i][1] = buff[i][index + 7];
        help [i][2] = buff[i][index + 8];
        help [i][3] = '\0';
    }
    for (int i = 0; i < size; i++){
        numberHelp[i][1] = atoi(help[i]);
        numberHelp[i][1] = numberHelp[i][0] + numberHelp[i][1]%100 + numberHelp[i][1]/100*60;
    }

    char time[6];
    cout<<"Введите время ";
    cin >> time;
    for (int i = 0; i < size; i++){
        help [i][0] = time[0];
        help [i][1] = time[1];
        help [i][2] = time[3];
        help [i][3] = time[4];
        help [i][4] = '\0';
    }
    for (int i = 0; i < size; i++){
        numberHelp[i][2] = atoi(help[i]);
        if(numberHelp[i][2]%100>59||numberHelp[i][2]%100<-1||numberHelp[i][2]/100>24||numberHelp[i][2]/100<1){
            cout << "Ошибка ввода"<<endl;
            return;}
            numberHelp[i][2] = numberHelp[i][2]%100 + numberHelp[i][2]/100*60;
    }
    int counter = size;
    for (int i = 0; i < size; i++){
        if(numberHelp[i][0]<=numberHelp[0][2]&&numberHelp[i][1]>=numberHelp[0][2]){
            cout <<buff [i] <<endl;
            counter--;
        }
    }
    if (counter == size){
        cout<<"Ничего не найдено\n";
    }
}

void findAuthor (char buff[20][100], int size){
    int index = 0;
    int indexNum = 0;
    char buffAuthorHelp[size][100];
    char buffAuthor[size][100];
    cout<<endl;
    for (int i = 0; i < size; i++){
        index = strcspn (buff[i], ",");
        strncpy(buffAuthorHelp[i],buff[i] + index+2, (strlen(buff[i])-index));
        index = strcspn (buffAuthorHelp[i], ",");//вхождение второй запятой
        indexNum = strcspn (buffAuthorHelp[i], ":") - 3;
        strncpy(buffAuthor[i],buffAuthorHelp[i] + index+2, (indexNum - index-2));
    }

    char author[30];
    cout<<"Введите автора: ";
    cin >> author;
    int counter = size;
    for (int i = 0; i < size; i++){
    char* pos = strstr (buffAuthor[i], author);
        if(pos!=NULL){
            cout<<buff[i]<<endl;
            counter--;
        }
    }
    if (counter == size){
        cout <<"Ничего не найдено\n";
    }
}

void menu (const char*fname, char buff[20][100], int size){
    while (1) {
    size = fillBuff(buff, fname);
    cout  <<"1. Информация про все выступления\n" << "2. Узнать что идет в выбранный момент\n" << "3. Узнать выступления автора\n" << "4. Добавить информацию\n" << "5. Выход из программы\n"<< "Выберите действие:";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            displayChar(buff, size);
            break;
        case 2:
            checkTime (buff, size);
            break;
        case 3:
            findAuthor (buff, size);
            break;
        case 4:
            add(fname);
            size = fillBuff(buff, fname);
            break;
        case 5:
            return;
        default:
            cout << "Некорректный номер\n";
    }
    }
}

void add (const char*fname){
char info[100];
cout <<"Добавьте новую информацию:";
cin.ignore();
cin.getline(info, 100);
ofstream fout;
fout.open (fname, ofstream::app | ios :: binary);
fout.seekp (0, ios::end);
if (!fout) {
cout << "Ошибка открытия файла1"; return ;
}
fout << info;
fout.close();
cout<<"\nИнформация  '"<<info<<"'  была записана\n";
}

