#include "student.h"
#include <iostream>

using namespace std;

Student::Student() {
    id = 0;
    name = "";
    cgpa = 0.0;
}

Student::Student(int id, string name, double cgpa) {
    this->id = id;
    this->name = name;
    this->cgpa = cgpa;
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
