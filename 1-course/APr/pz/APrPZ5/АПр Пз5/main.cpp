//15. Знайти середній (за місцем розташування) символ рядка та вставити його в початок та в кінець рядка.
#include <iostream>
using namespace std;
char* edit (char*);

int main() {
    char *str= new char[]{};
    cout<<"Enter your message: ";
    cin.getline(str,100);
    str = edit(str);
    cout<<"The result of edit: "<<str<<endl;
    return 0;
}

char* edit (char *str){
    int size = strlen(str);
    int mid = size/2;
    char help[size+2];
    help[0] = str [mid];
    help[1] = '\0';
    strcat (help,str);
    strncat(help, help,1);
    strcpy (str, help);
    return str;
}
