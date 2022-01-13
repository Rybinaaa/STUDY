#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void displayArr (int *arr, int size);
void coctailSort (int *arr, int size);
void heapSort(int *arr, int size);
void heapify(int arr[], int size, int i);
void shellSort(int *arr, int size);
void copyArr (int *arr, int *arr2, int size);


int main() {
    srand( static_cast<unsigned int>(time(nullptr)));
    int size = 810000;
    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        arr[i] = rand()%65536;
    }
    srand(time(NULL));
    unsigned long t, t1, t2, t3;
    int *arr1 = new int [size];
    int *arr2 = new int [size];
    copyArr (arr, arr1, size);
    copyArr (arr, arr2, size);
   // displayArr(arr, size);
    t = clock();
    coctailSort(arr, size);
    t1 = clock() - t;
    cout << fixed << "Час виконання сортування вибором: " << ((double)t1) / CLOCKS_PER_SEC << " секунд" << endl;
    t = clock();
    heapSort(arr1, size);
    t2 = clock() - t;
    cout << fixed << "Час виконання сортування вибором: " << ((double)t2) / CLOCKS_PER_SEC << " секунд" << endl;
    t = clock();
    shellSort(arr2, size);
    t3 = clock() - t;
    cout << fixed << "Час виконання сортування вибором: " << ((double)t3) / CLOCKS_PER_SEC << " секунд" << endl;
    //displayArr(arr, size);
   // displayArr(arr1, size);
   // displayArr(arr2, size);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;

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

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
  
    if (l < size && arr[l] > arr[largest]){
        largest = l;}
    if (r < size && arr[r] > arr[largest]){
        largest = r;}
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
  
void heapSort(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i);}
  
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void shellSort(int *arr, int size)
{
    for (int gap = size/2; gap > 0; gap /= 2)
       {
    for (int i = gap; i < size; i++)
       {
           for (int j = i; j >= gap; j -= gap){
                if (arr[j - gap] > arr[j]){
                    swap (arr[j], arr[j-gap]);
                    }
                }
        }
        }
}
  
void displayArr (int *arr, int size){
    for (int i = 0; i < size; i++){
        cout <<"    "<< arr[i];
    }
    cout<<endl;
}
void copyArr (int *arr, int *arr2, int size){
    for (int i = 0; i<size; i++){
        arr2[i] = arr[i];
    }
}
