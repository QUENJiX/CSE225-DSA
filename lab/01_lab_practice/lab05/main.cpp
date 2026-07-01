#include <iostream>
#include <string>
#include "unsortedtype.h"
#include "unsortedtype.cpp"   // Needed because UnsortedType is a template class.
using namespace std;

class Student
{
private:
    int id;
    string name;
    double cgpa;

public:
    Student()
    {
        id = 0;
        name = "";
        cgpa = 0.0;
    }

    Student(int studentId, string studentName, double studentCgpa)
    {
        id = studentId;
        name = studentName;
        cgpa = studentCgpa;
    }

    bool operator==(const Student &other) const
    {
        return id == other.id;
    }

    void Print() const
    {
        cout << id << ", " << name << ", " << cgpa << endl;
    }
};

void PrintIntegerList(UnsortedType<int> &list)
{
    int item;
    list.Reset();

    for (int i = 0; i < list.Length(); i++)
    {
        list.GetNext(item);
        cout << item << " ";
    }
    cout << endl;
}

void PrintStudentList(UnsortedType<Student> &list)
{
    Student student;
    list.Reset();

    for (int i = 0; i < list.Length(); i++)
    {
        list.GetNext(student);
        student.Print();
    }
}

void PrintSearchResult(UnsortedType<int> &list, int item)
{
    bool found;
    list.Search(item, found);

    if (found)
    {
        cout << "Item is found" << endl;
    }
    else
    {
        cout << "Item is not found" << endl;
    }
}

void PrintFullStatus(UnsortedType<int> &list)
{
    if (list.IsFull())
    {
        cout << "List is full" << endl;
    }
    else
    {
        cout << "List is not full" << endl;
    }
}

int main()
{
    UnsortedType<int> intList;

    intList.Insert(5);
    intList.Insert(7);
    intList.Insert(6);
    intList.Insert(9);

    PrintIntegerList(intList);
    cout << intList.Length() << endl;

    intList.Insert(1);
    intList.Insert(12);

    PrintIntegerList(intList);

    PrintSearchResult(intList, 4);
    PrintSearchResult(intList, 5);
    PrintSearchResult(intList, 9);
    PrintSearchResult(intList, 10);

    PrintFullStatus(intList);

    intList.Delete(5);
    PrintFullStatus(intList);
    PrintIntegerList(intList);

    intList.Delete(1);
    PrintIntegerList(intList);

    intList.Delete(6);
    PrintIntegerList(intList);

    intList.Delete(16);

    cout << endl;

    UnsortedType<Student> studentList;

    studentList.Insert(Student(15234, "Jon", 2.6));
    studentList.Insert(Student(13732, "Tyrion", 3.9));
    studentList.Insert(Student(13569, "Sandor", 1.2));
    studentList.Insert(Student(15467, "Ramsey", 3.8));
    studentList.Insert(Student(16285, "Arya", 3.1));

    studentList.Delete(Student(15467, "", 0.0));
    PrintStudentList(studentList);

    return 0;
}
