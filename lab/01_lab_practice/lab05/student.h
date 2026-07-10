#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    double cgpa;

public:
    Student();
    Student(int id, string name, double cgpa);

    bool operator==(Student other);
    bool operator!=(Student other);

    void Print();
};
#endif
