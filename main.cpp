#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  int group;
  int grades[5];
};

void readStudent(Student& student) {
  cout << "enter name: ";
  cin >> student.name;
  cout << "enter 5 grades: ";
  for (int i = 0; i < 5; i++) {
    cin >> student.grades[i];
  }
  cout << "enter group: ";
  cin >> student.group;
}

void printStudent(Student student) {
  cout << student.name << ' ' << student.group << ' ';
  for (int j = 0; j < 5; j++) {
    cout << student.grades[j] << ' ';
  }
  cout << "\n";
}

void printSortedStudents(vector<Student> a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size() - 1; j++) {
      if (a[j].group < a[j + 1].group) {
        swap(a[j], a[j + 1]);
      }
    }
  }
  for (int i = 0; i < a.size(); i++) {
    printStudent(a[i]);
  }
}

int main(int argc, char* argv[]) {
  vector<Student> a;
  int menu;
  while (true) {
    cout << "0 - exit\n"
         << "1 - add student\n"
         << "2 - print all students\n"
         << ": ";
    cin >> menu;
    if (menu == 0) {
      break;
    } else if (menu == 1) {
      Student st;
      readStudent(st);
      a.push_back(st);
    } else if (menu == 2) {
      printSortedStudents(a);
    }
  }
}
