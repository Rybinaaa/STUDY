//16. Згенерувати випадкове число n в проміжку від 30 до 50. Заповнити вхідний файл n дійсними числами в діапазоні від -5.5 до 5.5. Записати вихідний файл, помножив кожне третє число на подвоєну суму першого та останнього від’ємних чисел.
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;
void fillffile(const char*fname);
void fillsfile (const char*fname2,const char*fname); void displayfile(const char*fname);
int main () {
srand(static_cast<unsigned int>(time(nullptr))); srand( static_cast<unsigned
int>(time(nullptr)));
const char* fname = "first.txt"; const char* fname2 = "second.txt";
fillffile(fname); fillsfile(fname2,fname); cout<<"first file"<<endl; displayfile (fname); cout<<endl<<"second file"<<endl; displayfile (fname2);
}
void fillffile(const char*fname){
int size=(rand()%21+30);
 ofstream fout;
fout.open (fname,ios::binary);
if (!fout) {
cout << "Ошибка открытия файла"; return ;
}
double number;
for (int i=0; i<size; i++) { number=rand()%11-5.5; fout.write
((char*)&number,sizeof(number)); }
fout.close(); }
void displayfile(const char*fname){ ifstream fin;
fin.open (fname, ios::binary); if (!fin) {
cout<<"Ошибка открытия файла";
return; }
double number;
while (fin.peek() != -1) {
fin.read((char*)&number, sizeof(double)); cout << setw(8) << number;
}
fin.close(); }
void fillsfile (const char*fname2,const char*fname){ double number2;
double minus =0.0;
double minuslast = 0.0; ifstream fin2;
fin2.open (fname, ios::binary); while(fin2.peek()!= -1){

 fin2.read ((char*)&number2,sizeof(number2)); if(number2<0){
minus=number2;
break; }
}
fin2.seekg(0); while(fin2.peek()!= -1){
fin2.read ((char*)&number2,sizeof(number2)); if(number2<0)
minuslast=number2; }
ofstream fout2;
fout2.open (fname2,ios::binary); if (!fout2.is_open()) {
cout<<"Ошибка открытия файла";
return; }
else{
int i;
i=0;
fin2.seekg(0);
while (fin2.peek()!=-1) {
fin2.read ((char*)&number2,sizeof(number2));
i++;
if (i%3==0){
number2=number2*2*(minuslast+minus);
fout2.write ((char*)&number2,sizeof(number2));
} else{
fout2.write ((char*)&number2,sizeof(number2));
}

} fin2.close(); fout2.close();
}}
