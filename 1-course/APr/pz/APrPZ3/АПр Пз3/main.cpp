//19.Дан массив − n элементов целого типа. Найти сумму элементов, расположенных до первого отрицательного элемента. Если отрицательных элементов нет, то выдать соответствующее сообщение.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;
void fillarr(int*, int);
void coutarr(int*, int);
void sumfabs(int*, int*, int); void sumarr (int*,int*, int ); void result (int, int);
int main () {
int size;
cout<<"Enter size of array"<<endl; cin>>size;
int* arr = new int[size];
fillarr (arr, size);
int s=0,r=0; coutarr(arr,size); sumfabs (arr,&r,size); sumarr (arr, &s, size); result (s,r);
delete[] arr; return 0;
}
 void fillarr(int *arr, int size)
{
srand( static_cast<unsigned int>(time(nullptr))); int n=0;
do
{
*(arr+n)= rand() % 200-100; n++;
} while (n < size); }
void coutarr (int *arr,int size) {
for (int i=0; i<size; i++) {
cout<<setw(4)<<arr[i]; }
}
void sumfabs (int *arr,int *r,int size) {
for (int i=0; i<size; i++) {
*r+=fabs(arr[i]);
}
}
void sumarr (int *arr,int *s, int size) {
int j=0;
while (j<size&&arr[j]>=0) {
*s+=arr[ j];
j++; }
}
void result (int s, int r) {
if(s==r)
{ cout <<endl<< "Отрицательных значений нет"<<endl;

 }
else
{cout<<endl<<s<<endl;} }
    
//16. Для масиву 6*6 з цілих елементів (числа в діапазоні від -100 до 0) знайти стовпчики з мінімальним і максимальним елементом. Поміняти їх місцями. Якщо в одному стовпчику, то зміну не виконувати.
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
void fillarr (int**, int, int);
void coutarr (int**, int, int);
void mini (int**,int*,int,int);
void maxi (int**,int*,int,int); void swap (int**, int, int, int,int); void coutresult (int **,int,int); void coutmax (int**, int, int); void coutmin (int**, int, int);

int main () {
int row,col;
cout<<"Enter count of rows in array"<<endl; cin>>row;
cout<<"Enter count of columns in array"<<endl; cin>>col;
int** arr = new int* [row];
for (int i = 0; i < row; i++) {
arr[i] = new int[col]; }
int a = 0,b=0;
fillarr (arr, row, col);
mini (arr,&a,row, col); maxi (arr,&b,row, col); coutarr (arr, row, col);

 coutmax (arr,row,col); coutmin (arr,row,col); swap (arr,row,col,a,b); coutresult (arr, row, col); for (int i = 0; i < row; i++) {
delete[] arr[i]; }
delete[] arr;
return 0; }
void fillarr (int** arr,int row,int col) {
for (int i=0; i<row; i++)
{
for (int j=0; j<col; j++)
{
arr[i][j]=-(rand() % 98)-1;
} cout<<endl;
} }
void coutarr (int** arr,int row,int col) {
for (int i=0; i<row; i++)
{
for (int j=0; j<col; j++)
{ cout<<setw(4)<<arr[i][j]; }
cout<<endl; }
}
void mini (int **arr,int *a, int row, int col) {
int min=arr[0][0];
for (int i=0; i<row; i++)
{
for (int j=0; j<col; j++)
{
if (min>arr[i][j])

 {
min=arr[i][j]; *a=j;
} }
} }
void maxi (int **arr,int *b, int row, int col) {
int max=arr[0][0];
for (int i=0; i<row; i++)
{
for (int j=0; j<col; j++)
{
if (max<arr[i][j]) {
max=arr[i][j];
*b=j; }
} }
}
void swap (int **arr,int row, int col, int a, int b) {
for (int i=0; i<row; i++)
{swap (arr[i][a],arr[i][b]);
}
}
void coutresult (int **arr,int row, int col) {
for (int i=0; i<row; i++)
{
cout<<endl;
for (int j=0; j<col; j++) {
cout<<setw(4)<<arr[i][j]; }
}
}

void coutmax (int**arr, int row, int col) {
int max=arr[0][0];

for (int i=0; i<row; i++) {
    for (int j=0; j<col; j++) {
        if (arr[i][j]>max){
            max=arr[i][j];
                    
            }
        }
    }
cout<<endl<<max;
}

void coutmin (int**arr, int row, int col) {
int min=arr[0][0];
for (int i=0; i<row; i++) {
for (int j=0; j<col; j++) {
if (arr[i][j]<min){min=arr[i][j];} }
}
cout<<endl<<min;
}
