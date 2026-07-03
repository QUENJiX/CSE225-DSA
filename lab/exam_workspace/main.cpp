/*
    Exam starter for Lab 5: array-based UnsortedType<T>.

    Fast swaps:
    - Change int operations to the values from the question.
    - Replace Student with Book/Employee/Course if the custom object changes.
    - For unsorted delete, order is not preserved: deleted slot gets last item.
*/

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

    Student(int studentId, string studentName, double studentCgpa) {
        id = studentId;
        name = studentName;
        cgpa = studentCgpa;
    }

    bool operator==(const Student& other) const {
        return id == other.id;
    }

    void Print() const {
        cout << id << ", " << name << ", " << cgpa << endl;
    }
};

template <class T>
void PrintList(UnsortedType<T>& list) {
    T item;
    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        cout << item << " ";
    }
    cout << endl;
}

void PrintStudentList(UnsortedType<Student>& list) {
    Student item;
    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        item.Print();
    }
}

template <class T>
void PrintSearchResult(UnsortedType<T>& list, T item) {
    bool found;
    list.Search(item, found);

    if (found) {
        cout << "Item is found" << endl;
    } else {
        cout << "Item is not found" << endl;
    }
}

template <class T>
void PrintFullStatus(UnsortedType<T>& list) {
    if (list.IsFull()) {
        cout << "List is full" << endl;
    } else {
        cout << "List is not full" << endl;
    }
}

int main() {
    UnsortedType<int> numbers;

    numbers.Insert(5);
    numbers.Insert(7);
    numbers.Insert(6);
    numbers.Insert(9);

    PrintList(numbers);
    cout << "Length: " << numbers.Length() << endl;

    numbers.Insert(1);
    numbers.Insert(12);

    PrintList(numbers);

    PrintSearchResult(numbers, 4);
    PrintSearchResult(numbers, 5);
    PrintSearchResult(numbers, 9);
    PrintSearchResult(numbers, 10);

    PrintFullStatus(numbers);

    numbers.Delete(5);
    PrintFullStatus(numbers);
    PrintList(numbers);

    numbers.Delete(1);
    PrintList(numbers);

    numbers.Delete(6);
    PrintList(numbers);

    numbers.Delete(16);

    cout << endl;

    UnsortedType<Student> students;
    students.Insert(Student(15234, "Jon", 2.6));
    students.Insert(Student(13732, "Tyrion", 3.9));
    students.Insert(Student(13569, "Sandor", 1.2));
    students.Insert(Student(15467, "Ramsey", 3.8));
    students.Insert(Student(16285, "Arya", 3.1));

    students.Delete(Student(15467, "", 0.0));
    PrintStudentList(students);

    return 0;
}
