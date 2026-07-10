#include "student.h"
#include <iostream>
using namespace std;

Student::Student() {
    id = 0;
    name = "";
    cgpa = 0.0;
}
Student::Student(int sid, string sname, double scgpa) {
    id = sid;
    name = sname;
    cgpa = scgpa;
}

bool Student::operator==(Student other) {
    return id == other.id;
}
bool Student::operator!=(Student other) {
    return id != other.id;
}
void Student::Print() {
    cout << id << ", "
        << name << ", "
        << cgpa << endl;
}
