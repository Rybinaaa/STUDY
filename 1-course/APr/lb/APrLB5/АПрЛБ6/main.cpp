#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

enum type_of_performance { comedy, drama, fantasy };

struct Info {
  char name[40];
  type_of_performance genre;
  double price;
  int countOfActs;
  char beginTime[6];
  char duration[5];
  bool full_type_of_performance(const char* nameGenre)
  {
    if (!strcmp(nameGenre, "comedy"))
    {
      genre = comedy;
      return true;
    }
    if (!strcmp(nameGenre, "drama"))
    {
      genre = drama;
      return true;
    }
    if (!strcmp(nameGenre, "fantasy"))
    {
      genre = fantasy;
      return true;
    }
    return false;
  }

};

struct Performance {
  Info seance;
  char author[15];
};

//void fillFile(const char* fname);
int fillBuff(const char* fname, Performance* seances);
void add(const char* fname, int size);
void fillFile(const char* fname, Performance* seances, int size);
//void menu(const char* fname, char buff[20][100], int& size);
void display_array(const Performance* seances, int size);
const char* type_of_performances(type_of_performance genre);
void checkAuthor(Performance* seances, char findAuthor[20], int size);
void checkTime(Performance* seances, char time[6], int size);
void counterOfGenre(Performance* seances, int size);
void menu(Performance* seances, const char* fname, int& size);
char* writeBegin();
char* writeDuration();
int writeActs();
char* writeName();
char* write2Name();

ostream& operator << (ostream&, const Performance&);
istream& operator >> (istream&, Performance&);

int main() {

  const char* fname = "text.txt";
  Performance seances[30];
  int size = fillBuff(fname, seances);
  display_array(seances, size);
  menu(seances, fname, size);

  return 0;
}


const char* type_of_performances(type_of_performance genre)
{
  switch (genre)
  {
  case 0:
    return "comedy";
  case 1:
    return "drama";
  case 2:
    return "fantasy";
  }
}

ostream& operator << (ostream& stream, const Performance& seances) {
  stream << setw(20) << seances.seance.name << setw(20) << seances.author << setw(15)
    << seances.seance.beginTime << setw(15) << seances.seance.duration << setw(15) << setiosflags(ios::fixed | ios::showpoint)
    << setprecision(2) << seances.seance.price << setw(15)
    << seances.seance.countOfActs << setw(15) << type_of_performances(seances.seance.genre) << endl;
  return stream;
}
void display_array(const Performance* seances, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << seances[i];
  }
  cout << endl;
}

void add(const char* fname, int size) {
  char info[100];
  cout << "Добавьте новую информацию: ";
  cin.ignore();
  cin.getline(info, 100);
  ofstream fout;
  fout.open(fname, ofstream::app | ios::binary);
  fout.seekp(0, ios::end);
  if (!fout) {
    cout << "Ошибка открытия файла (1)"; return;
  }
  fout << info;
  fout.close();
  cout << "\nИнформация  '" << info << "'  была записана\n";
}

void fillFile(const char* fname, Performance* seances, int size) {
  ofstream fout(fname, ios::trunc);
  if (!fout) {
    cout << "Ошибка записи";
    return;
  }

  for (int i = 0; i < size; i++) {
    fout << seances[i].seance.name << "," << type_of_performances(seances[i].seance.genre) << "," << seances[i].author << "," << seances[i].seance.beginTime << "," << seances[i].seance.duration << "," << seances[i].seance.price << "," << seances[i].seance.countOfActs << ";";
  }
  fout.close();
}
int fillBuff(const char* fname, Performance* seances) {
  char buff[100];
  ifstream fin;
  fin.open(fname);
  if (!fin)
  {
    cout << "The file hasn't been opened." << endl;
    return -1;
  }
  int size = 0;
  while (fin.getline(buff, 100, ';')) {
    char* tmp;
    const char* semplate = ",;";
    tmp = strtok(buff, semplate);
    strcpy(seances[size].seance.name, tmp);
    tmp = strtok(NULL, semplate);
    seances[size].seance.full_type_of_performance(tmp);
    tmp = strtok(NULL, semplate);
    strcpy(seances[size].author, tmp);
    tmp = strtok(NULL, semplate);
    strcpy(seances[size].seance.beginTime, tmp);
    tmp = strtok(NULL, semplate);
    strcpy(seances[size].seance.duration, tmp);
    tmp = strtok(NULL, semplate);
    seances[size].seance.countOfActs = atof(tmp);
    tmp = strtok(NULL, semplate);
    seances[size].seance.price = atof(tmp);
    size++;
  }

  fin.close();
  return size;
}

void checkAuthor(Performance* seances, char findAuthor[20], int size) {
  for (int i = 0; i < size; i++) {
    if (!strcmp(seances[i].author, findAuthor)) {
      cout << seances[i];
    }
  }
}

void checkTime(Performance* seances, char time[6], int size) {
  int* begin = new int[size];
  int* end = new int [size];
  int findTime = 0;
  Performance* ptr;
  ptr = &seances[0];
  char* tmp;
  const char* semplate = ":";

  tmp = strtok(time, semplate);
  findTime += atof(tmp) * 60;
  tmp = strtok(NULL, "/n");
  findTime += atof(tmp);
  char* help = new char;
  for (int i = 0; i < size; i++) {
    strcpy(help, (ptr + i)->seance.beginTime);
    tmp = strtok(help, semplate);
    begin[i] = atof(tmp) * 60;
    tmp = strtok(NULL, "\n");
    begin[i] += atof(tmp);
    tmp = strtok((ptr + i)->seance.duration, semplate);
    end[i] = begin[i] + atof(tmp) * 60;
    tmp = strtok(NULL, "\n");
    end[i] += atof(tmp);
    if (findTime >= begin[i] && findTime <= end[i]) {
      cout << *(ptr + i);
    }
  }
  delete help;
}
void counterOfGenre(Performance* seances, int size) {
  int counter0 = 0;
  int counter1 = 0;
  int counter2 = 0;
  for (int i = 0; i < size; i++) {
    if (seances[i].seance.genre == 0) {
      counter0++;
    }
    if (seances[i].seance.genre == 1) {
      counter1++;
    }
    if (seances[i].seance.genre == 2) {
      counter2++;
    }
  }
  if (counter0 > counter1) {
    if (counter0 > counter2) cout << "comedy";
    else cout << "fantasy";
  }
  else if (counter2 > counter0 || counter2 > counter1) cout << "drama";
  else cout << endl << "Нет единого популярного жанра\n";
};

void menu(Performance* seances, const char* fname, int& size) {
  while (1) {
    cout << "1. Информация про все выступления\n" << "2.Узнать что идет в выбранный момент\n" << "3. Узнать выступления автора\n" << "4.Узнать самый популярный жанр\n" << "5. Добавить информацию\n" << "6.Выход из программы\n" << "Выберите действие:";
    int choice;
    char time[6];
    char findAuthor[20];
    cin >> choice;
    switch (choice) {
    case 1:
      display_array(seances, size);
      break;
    case 2:
      cout << endl << "Введите время";
      cin >> time;
      checkTime(seances, time, size);
      break;
    case 3:
      cout << endl << "Введите автора :";
      cin >> findAuthor;
      checkAuthor(seances, findAuthor, size);
      break;
    case 4:
      counterOfGenre(seances, size);
      break;
    case 5:
      cin >> *(seances + size);
      size++;
      break;
    case 6:
      fillFile(fname, seances, size);
      return;
    default:
      cout << "Некорректный номер\n";
      break;
    }
  }
}


istream& operator >> (istream& stream, Performance& seances) {
    cout << endl << "Введите название: ";
      strcpy(seances.seance.name, writeName());
      cout << endl << "Введите жанр ";
      char checking[10];
      cin >> checking;
      seances.seance.full_type_of_performance(checking);
      cout << endl << "Введите автора: ";
      strcpy(seances.author, write2Name());
      cout << endl << "Введите начало:  ";
      strcpy(seances.seance.beginTime, writeBegin());
      cout << endl << "Введите продолжительность: ";
      strcpy(seances.seance.duration, writeDuration());
      cout << endl << "Введите количество актов: ";
      seances.seance.countOfActs = writeActs();
      cout << endl << "Введите цену: ";
      stream >> seances.seance.price;
      return stream;
    }

    char* writeBegin() {
      char* time = new char[6]{};
      char* help = new char[6];
      cin >> time;
      strcpy(help, time);
      char* tmp;
      const char* semplate = ":";
      cout << strlen(time);
      if (strlen(time) < 5) {
        cout << "restart1";
        return writeBegin();
      }

      tmp = strtok(help, semplate);
      if (atof(tmp) > 24 || atof(tmp) <= 0) {
        cout << "restart2";
        return writeBegin();
      }

      tmp = strtok(NULL, "/n");

        delete[] help;

      if (atof(tmp) != 0 && atof(tmp) != 30) {
        cout << "restart3";
        return writeBegin();
      }
      else return time;
    }

    char* writeDuration() {
      char* duration = new char[5]{};
      char* help = new char[5];
      cin >> duration;
      strcpy(help, duration);
      char* tmp;
      const char* semplate = ":";
      cout << strlen(duration);
      if (strlen(duration) < 4) {
        cout << "restart1";
        return writeDuration();
      }

      tmp = strtok(help, semplate);

      if (atof(tmp) > 2 || atof(tmp) < 0) {
        cout << "Некорректно введенное время";
        return writeDuration();
      }

      tmp = strtok(NULL, "/n");

        delete[] help;

      if (atof(tmp) != 0 && atof(tmp) != 30) {
        cout << "restart3";
        return writeDuration();
      }

      else {
        return duration;
      }
    }

    int writeActs() {
      int c;
      cin >> c;
      if (c > 4 || c < 1) {
        cout << "количество актов от 1 до 4!";
        return writeActs();
      }
      else return c;
    }

    char* writeName() {
      char* name = new char[20]{};
      cin.ignore(1, '/n');
      cin.getline(name, 20);
      cout << name;
      return name;
    }

    char* write2Name() {
      char* name = new char[20]{};
      cin >> name;
      cout << name;
      return name;
    }
