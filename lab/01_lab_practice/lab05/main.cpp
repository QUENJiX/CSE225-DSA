#include <iostream>
#include "student.h"
#include "unsortedtype.h"
#include "unsortedtype.cpp"
using namespace std;

void PrintIntegerList(UnsortedType<int>& list) {
    int value;
    list.Reset();
    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(value);
        cout << value << " ";
    }
    cout << endl;
}

void PrintSearchResult( UnsortedType<int>& list, int searchValue) {
    bool found;
    list.Search(searchValue, found);
    if (found) {
        cout << "Item is found" << endl;
    }
    else {
        cout << "Item is not found" << endl;
    }
}

void PrintFullStatus(UnsortedType<int>& list) {
    if (list.IsFull()) {
        cout << "List is full" << endl;
    }
    else {
        cout << "List is not full" << endl;
    }
}

void PrintStudentList(UnsortedType<Student>& list) {
    Student student;
    list.Reset();
    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(student);
        student.Print();
    }
}

int main() {
    cout << "INTEGER LIST" << endl;
    cout << "------------" << endl;

    UnsortedType<int> numbers;
    numbers.Insert(5);
    numbers.Insert(7);
    numbers.Insert(6);
    numbers.Insert(9);

    cout << "List: ";
    PrintIntegerList(numbers);

    cout << "Length: " << numbers.Length() << endl;
    numbers.Insert(1);
    // The list is full, so this produces an error.
    numbers.Insert(12);

    cout << "List: ";
    PrintIntegerList(numbers);
    cout << "Search for 4: ";
    PrintSearchResult(numbers, 4);
    cout << "Search for 5: ";
    PrintSearchResult(numbers, 5);
    cout << "Search for 9: ";
    PrintSearchResult(numbers, 9);
    cout << "Search for 10: ";
    PrintSearchResult(numbers, 10);
    PrintFullStatus(numbers);

    // [5, 7, 6, 9, 1]
    // Delete 5 by replacing it with the final item, 1.
    numbers.Delete(5);
    PrintFullStatus(numbers);
    cout << "After deleting 5: ";
    PrintIntegerList(numbers);
    // [1, 7, 6, 9]

    // Delete 1 by replacing it with 9.
    numbers.Delete(1);
    cout << "After deleting 1: ";
    PrintIntegerList(numbers);
    // [9, 7, 6]

    numbers.Delete(6);
    cout << "After deleting 6: ";
    PrintIntegerList(numbers);

    // 16 is not in the list.
    numbers.Delete(16);

    // Part 2: Student list
    cout << endl;
    cout << "STUDENT LIST" << endl;
    cout << "------------" << endl;

    UnsortedType<Student> students;
    students.Insert(Student(15234, "Jon", 2.6));
    students.Insert(Student(13732, "Tyrion", 3.9));
    students.Insert(Student(13569, "Sandor", 1.2));
    students.Insert(Student(15467, "Ramsey", 3.8));
    students.Insert(Student(16285, "Arya", 3.1));

    cout << "Original student list:" << endl;
    PrintStudentList(students);
    Student studentToDelete(15467, "", 0.0);
    students.Delete(studentToDelete);
    cout << endl;
    cout << "After deleting student 15467:" << endl;
    PrintStudentList(students);
    return 0;
}
