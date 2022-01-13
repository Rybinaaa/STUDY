#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum type_of_valute {euro, dollar, pound};

//15. Інформація про банківський вклад містить: ідентифікатор вкладу; тип валюти; коефіцієнт для переведення суми у гривні; сума у визначеній валюті. Створити масив банківських вкладів. Реалізувати наступні можливості:
//– розрахувати суму всіх вкладів у заданній валюті;
//– відсортувати масив за зростанням сум вкладу, переведених у гривні.

struct Bank{
    int identificator;
    type_of_valute type;
    double koef;
    int sizeInvest;
    int getInvestUAH(){
        return sizeInvest * koef;
    }
    int InvestUAH;
};

ostream& operator << (ostream&, const Bank&);
istream& operator >> (istream&, Bank&);
void fillStruct(Bank*invest, int size);
void getTypeOfValute(char checking[5],Bank&invest);
const char* displayValute(type_of_valute type);
void displayStruct(Bank*invest, int size);
int sumInvest(Bank*invest, char valute[10], int size);
void sort(Bank*invest, int size);

int main(){
    int size;
    cout << "Введите количество вкладов: ";
    cin >> size;
    Bank*invest = new Bank[size];
    fillStruct(invest, size);
    displayStruct(invest, size);
    char valute[10];
    cout << endl << "Выберите нужную валюту ";
    cin >> valute;
    int sum = sumInvest(invest, valute, size);
    cout << sum;
    cout << endl << "Отсортированные данные\n";
    sort(invest, size);
    displayStruct(invest, size);
    return 0;
}
        
const char* displayValute(type_of_valute type)
{
  switch (type)
  {
  case 0:
    return "euro";
  case 1:
    return "dollar";
  case 2:
    return "pound";
  }
}

ostream& operator << (ostream&stream, const Bank&invest){
    stream << setw(15)<<left << invest.identificator << setw(10) << displayValute(invest.type)<< setw(10) <<invest.koef << setw(10) << invest.sizeInvest << invest.InvestUAH << "грн" << endl;
    return stream;
}

istream& operator >> (istream&stream, Bank&invest){
    Bank*inv = &invest;
    cout << endl << "Введите идентификатор вклада ";
    stream >> inv->identificator;
    cout << endl << "Введите тип валюты вклада ";
    char checking[10];
    cin >> checking;
    getTypeOfValute(checking, invest);
    cout << endl << "Введите инвестицию ";
    stream >> inv->sizeInvest;
    inv->InvestUAH = inv->getInvestUAH();
    return stream;
}

void fillStruct(Bank*invest, int size){
    for(int i = 0; i < size; i++){
        cout << i + 1 << " вклад";
        cin >> *(invest+i);
    }
}


void getTypeOfValute(char checking[10],Bank&invest) {
    if (!strcmp(checking, "euro"))
    {
    invest.type = euro;
    invest.koef = 32.5;
    }
    if (!strcmp(checking, "dollar"))
    {
      invest.type = dollar;
      invest.koef = 27.3;
    }
    if (!strcmp(checking, "pound"))
    {
      invest.type = pound;
      invest.koef = 37.8;

    }
}

void displayStruct(Bank*invest, int size){
    for(int i = 0; i < size; i++){
        cout << "№"<< invest[i];
    }
}

int sumInvest(Bank*invest, char valute[10], int size){
    int sum = 0;
    if (!strcmp(valute, "euro"))
    {
        for(int i = 0; i < size; i++){
            if (invest[i].type == euro){
                sum += invest[i].sizeInvest;
            }
        }
    }
    if (!strcmp(valute, "dollar"))
    {
        for(int i = 0; i < size; i++){
            if (invest[i].type == dollar){
                sum += invest[i].sizeInvest;
            }
        }
    }
    if (!strcmp(valute, "pound"))
    {
        for(int i = 0; i < size; i++){
            if (invest[i].type == pound){
                sum += invest[i].sizeInvest;
            }
        }

    }
    return sum;
}

void sort(Bank*invest, int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if(invest[j].InvestUAH > invest[j+1].InvestUAH){
                swap(invest[j], invest[j+1]);
            }
        }
    }
}
