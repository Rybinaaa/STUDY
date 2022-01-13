/*Вхідні файли містять цілі числа у діапазоні від -30 до 30. Обчислювати суми пар чисел з двох файлів, починаючи з 5 елемента, потім 4, 3, 2 та перші. Далі береться 10 елементи, після нього 9, 8, 7, 6 і так далі. Суми записуються до вихідного файлу. Залишок більшого файлу заноситься за тим же правилом: спочатку елемент, за номером кратний п’яти, далі чотири від нього  в зворотному порядку.*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

void fillfiles(const char *fname, int size);
void resultfile (const char* fname1, const char* fname2, const char* fname3);
void displayfile(const char*fname);
int sizebytefile(const char* fname);
void add (const char*fname);
void menu (const char* fname1, const char* fname2, const char* fname3);
int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); srand( static_cast<unsigned
    int>(time(nullptr)));
    const char* fname1 = "first.txt";
    const char* fname2 = "second.txt";
    const char* fname3 = "third.txt";
    int size=rand()%31+10;
    fillfiles (fname1, size);
    size=rand()%31+10;
    fillfiles (fname2, size);
    menu (fname1, fname2, fname3);

}
void fillfiles(const char *fname, int size)
{
    ofstream fout;
    fout.open (fname, ios:: binary);
    if (!fout) {
    cout << "Ошибка открытия файла1"; return ;
    }
    int number;
    for (int i=0; i<size; i++) {
    number=rand()%61-30;
    fout.write
    ((char*)&number,sizeof(number)); }
    fout.close();
}
void resultfile (const char* fname1, const char* fname2, const char* fname3)
{
    int number1=sizebytefile (fname1);
    int number2=sizebytefile (fname2);
    int step = 5;
    ifstream fin1;
    ifstream fin2;
    ofstream fout3;
    if (number1>number2){
    fin1.open (fname1, ios:: binary);//фин1 всегда читает наибольший файл
    fin2.open (fname2, ios:: binary);}
    else {
        fin1.open (fname2, ios:: binary);
        fin2.open (fname1, ios:: binary);
        swap (number1, number2);
    }
    fout3.open (fname3, ios::binary);
    if (!fin1&&!fin2) {
    cout << "Ошибка  файла2"; return ;
    }
    if (!fout3){
    cout << "Ошибка открытия файла3"; return ;
    }
       
        fin1.seekg (6*(sizeof(int)),ios::beg);
        fin2.seekg (6*(sizeof(int)),ios::beg);

    int max= number2/20;
    int max2= number1/20;
    cout<<number2<<endl;
    int j=0;
    while (j<max){
    for (int i =0; i<5; i++){
        
        fin1.seekg (-2*(sizeof(int)), ios::cur);
        fin2.seekg (-2*(sizeof(int)), ios::cur);
        fin1.read ((char*)&number1,sizeof(number1));
        fin2.read ((char*)&number2,sizeof(number2));
        int r=(number1+number2);
        fout3.write ((char*)&r,sizeof(int));
    }
        fin1.seekg ((2*step*(sizeof(number1))),ios::cur);
        fin2.seekg ((2*step*(sizeof(number2))),ios::cur);
        j++;

    }
    j*=5;
    fin2.seekg (j*sizeof(int),ios::beg);
    
    while(fin2.peek()!= -1){
        fin2.read ((char*)&number2,sizeof(int));
        fout3.write ((char*)&number2,sizeof(int));

    }
    fin1.seekg((6+j)*(sizeof(int)),ios::beg);
    j/=5;
    while (j<max2){
    for (int i =0; i<5; i++){
        
        fin1.seekg (-2*(sizeof(int)), ios::cur);
        fin1.read ((char*)&number1,sizeof(number1));
        fout3.write ((char*)&number1,sizeof(int));
    }
        fin1.seekg ((2*step*(sizeof(number1))),ios::cur);
        fin2.seekg ((2*step*(sizeof(number2))),ios::cur);
        j++;
    }
    j*=5;
    fin1.seekg(j*sizeof(int),ios::beg);
    while(fin1.peek()!= -1){
        fin1.read ((char*)&number1,sizeof(int));
        fout3.write ((char*)&number1,sizeof(int));

    }

    
    fin1.close();
    fin2.close();
    fout3.close();
    
                    
    }

void displayfile(const char*fname)
{
ifstream fin5;
fin5.open (fname, ios::binary); if (!fin5) {
cout<<"Ошибка открытия файла";
return; }
int number;
    int n=0;
while (fin5.peek() != -1) {
    n++;
fin5.read((char*)&number, sizeof(int));
cout << setw(4)<<n<<". " << number;
  }
    fin5.close(); }

int sizebytefile(const char* fname){
    ifstream fin5;
    fin5.open (fname, ios::binary); if (!fin5) {
    cout<<"Ошибка открытия файла";
    return 0; }
    int number;
    fin5.seekg (0, ios::end);
    number=(int)fin5.tellg();
    fin5.close();
    return number;
}
void menu (const char* fname1, const char* fname2, const char* fname3){
    while (1) {
    cout<<endl<<"Choose your action";
    cout<<endl<<"1 - display the first file"<<endl<<"2 - display the second file"<<endl<<"3 - add an element to the first file"<<endl<<"4 - add an element to the second file"<<endl<<"5 - display the third file"<<endl<<"6 - exit";
    int n;
        cout<<endl<<"Your choice:";
    cin>>n;
        cout<<n;
    switch (n){
        case 1:
            cout<<"\nfirst file"<<endl;
            displayfile (fname1);
            break;
        case 2:
            cout<<"\nsecond file"<<endl;
            displayfile (fname2);
            break;
        case 3:
            add(fname1);
            break;
        case 4:
            add(fname2);
            break;
        case 5:
            resultfile (fname1, fname2, fname3);
            cout<<"\nthird file"<<endl;
            displayfile (fname3);
            break;
        case 6:
            return;
    }
       // system("pause");
        //system ("cls");
        
    }
}
void add (const char*fname){
    int num;
    cout <<endl<<"add some element";
    cin>>num;
    ofstream fout;
    fout.open (fname, ofstream::app);
    fout.seekp (0, ios::end);
    if (!fout) {
    cout << "Ошибка открытия файла1"; return ;
    }
    fout.write
    ((char*)&num,sizeof(int));
    fout.close();
    cout<<"The element  "<<num<<" has been written";
}


