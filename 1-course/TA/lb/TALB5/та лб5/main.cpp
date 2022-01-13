//Варіант 20. Кожний елемент списку містить символьний рядок, не більше 10 символів.   Реалізувати додавання та видалення елементів з заданої позиції. Додатково реалізувати операцію розбиття списку на два у відповідності з номером позиції, з якої починається розбиття.
//Особливості динамічної реалізації: двоспрямований лінійний список, додатково реалізувати функцію, що визначає, чи є заданий рядок у списку.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

struct Info {
    char symb[10];
};

struct List {
    Info info;
    List* next;
    List* prev;
};

bool addElement(List *&, List *&, Info , int);
void showElement(List *);
void fillList(List *&,List *&, int );
bool checkPos(List *, List *, int );
void devide (List *&, List *&, List *&, List *&, int );
    
int main(){
    srand(static_cast<unsigned int>(time(nullptr))); srand( static_cast<unsigned
    int>(time(nullptr)));

    
    List *begin = NULL;
    List *begin1 = NULL;
    List *begin2 = NULL;
    
    List *end = NULL;
    List *end1 = NULL;
    List *end2 = NULL;
    addElement(begin, end, {"1"}, 1);
    addElement(begin, end, {"2"}, 1);
    addElement(begin, end, {"3"}, 1);
    addElement(begin, end, {"4"}, 1);
    addElement(begin, end, {"5"}, 1);
    addElement(begin, end, {"6"}, 1);
//    devide (begin, begin1, begin2, end, end1, end2, 3)
    
  //  cout << end;
    showElement(begin);
    
    
    
    return 0;
}
void showElement(List *begin){
    while (begin) {
        cout << setw(6) << begin->info.symb;
        begin = begin -> next;
    }
}

bool addElement(List *&begin, List *&end, Info element, int position){
    List *ptr = new List;
    List *numberPtrBeg = new List;

    ptr -> info = element;
    if (position == 1){
        if(!begin){
            end = ptr;
        }
        begin -> prev = ptr;
        ptr -> next = begin;
        begin = ptr;
        return true;
    }
    
    numberPtrBeg = begin;
    
    int i = 1;
    while (i != position - 1 && numberPtrBeg){
           i++;
        numberPtrBeg = numberPtrBeg->next;
    }
    if (!numberPtrBeg)
    {
           delete numberPtrBeg;
           return false;
    }
    ptr->next = numberPtrBeg->next;
    numberPtrBeg->next = ptr;
    

    if(!ptr->next){
        ptr = end;
    }
    else{
        ptr -> prev = numberPtrBeg;
    }
    return true;
    
}

//void fillList(List *&begin,List *&end, int size){
//    char help[10];
//    while (size!=0)
//    {
//        for (int i = 0; i < 9; i++){
//        help[i] = rand()%50;
//            size--;}
//        cout << help;
////        addElement(begin, end, {help});
//    }
//}

void devide (List *&begin, List *&begin1, List *&begin2, List *&end, List *&end1,List *&end2, int position){
    if (checkPos(begin, end, position)) {
    for (int i = 0; i < position; i++){
        addElement(begin1, end1, begin->info, 1);
        begin = begin -> next;
        }
    }
    while(end != begin){
        addElement(begin2, end2, begin->info, 1);
        end = end -> prev;
    }
}

bool checkPos(List *begin, List *end, int position){
    for (int i = 0; i < position; i++){
        begin = begin -> next;
        if(begin == end && (i < (position-1))){
            return false;
        }
    }
    return true;
}
