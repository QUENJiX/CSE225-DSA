#include <iostream>
#include <string>
#include "unsortedtype.h"
#include "unsortedtype.cpp"
using namespace std;

class Student {
   private:
    int id;
    string name;
    double cgpa;

   public:
    Student() {
        id = 0;
        name = "";
        cgpa = 0.0;
    }

    Student(int i, string n, double c) {
        id = i;
        name = n;
        cgpa = c;
    }

    bool operator==(Student other) {
        return id == other.id;
    }

    void Print() {
        cout << id << ", " << name << ", " << cgpa << endl;
    }
};

void printIntList(UnsortedType<int>& list) {
    int item;
    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        cout << item << " ";
    }
    cout << endl;
}

void printStudentList(UnsortedType<Student>& list) {
    Student student;
    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(student);
        student.Print();
    }
}

int main() {
    UnsortedType<int> numbers;

    numbers.Insert(5);
    numbers.Insert(7);
    numbers.Insert(6);
    numbers.Insert(9);

    cout << "Numbers: ";
    printIntList(numbers);

    bool found;
    numbers.Search(6, found);
    cout << "Search 6: " << (found ? "found" : "not found") << endl;

    numbers.Delete(7);
    cout << "After deleting 7: ";
    printIntList(numbers);

    UnsortedType<Student> students;
    students.Insert(Student(15234, "Rahim", 3.45));
    students.Insert(Student(15467, "Karim", 3.10));
    students.Insert(Student(15890, "Nila", 3.80));

    students.Delete(Student(15467, "", 0.0));

    cout << "Students after deleting ID 15467:" << endl;
    printStudentList(students);

    return 0;
}
