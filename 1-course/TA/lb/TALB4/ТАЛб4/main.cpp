#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>
using namespace std;
void coutArr (int *arr,int size);
void fillArr(int *arr, int size);
void coctailSort (int *arr, int size);
bool search(int find, int *arr, int size);

int main() {
    int size;
    cout<<"Enter size of array: "<<endl;
    cin>>size;
    int* arr = new int[size];
    fillArr (arr, size);
    coctailSort (arr,size);
    coutArr(arr, size);
    int find;
    cout << endl << "Enter some number: ";
    cin >> find;
    if (search(find, arr, size)){
        cout << find << " was found";
    }
    else {
        cout << find << " wasn't found";
    }
    cout << endl;
    
}

bool search(int find, int *arr, int size){
    if (size <= 0){
        return false;
    }
    int middle=size/2;
    if (find > arr[middle])
        return search(find, &arr[middle + 1], size - middle - 1);
    else if (find < arr[middle])
        return search(find, arr, middle);
    return true;
}

void coutArr (int *arr,int size){
    for (int i=0; i<size; i++)
    {
        cout<<setw(4)<<arr[i];
    }
}

void fillArr(int *arr, int size){
    srand( static_cast<unsigned int>(time(nullptr)));
    int n=0;
    while (n < size)
    {
    *(arr+n)= rand() % 99;
        n++;
    };
}

void coctailSort (int *arr, int size){
    bool notSort = true;
    int start = 0;
    int finish = size - 1;
    
    while (notSort){
        notSort = false;
        
        for (int i = 0; i < finish; i++){
            if (arr[i] > arr[i+1]){
                swap (arr[i], arr[i+1]);
                notSort = true;
            }
        }
        
        if (!notSort){
            break;
        }
        
        notSort = false;
        finish--;
        
        for (int i = finish - 1; i >= start; i--){
            if (arr[i] > arr[i+1]){
                swap (arr[i],arr[i+1]);
                notSort = true;
            }
        }
        
        start++;

    }
}



