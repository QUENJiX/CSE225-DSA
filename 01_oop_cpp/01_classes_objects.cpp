#include <bits/stdc++.h>
using namespace std;

class Student {
   private:
    string name;
    int id;
    vector<int> marks;

   public:
    static int createdCount;

    Student(string studentName, int studentId, vector<int> studentMarks)
        : name(move(studentName)), id(studentId), marks(move(studentMarks)) {
        ++createdCount;
    }

    string getName() const {
        return name;
    }

    double average() const {
        if (marks.empty()) {
            return 0.0;
        }

        int total = accumulate(marks.begin(), marks.end(), 0);
        return static_cast<double>(total) / marks.size();
    }

    void addMark(int mark) {
        marks.push_back(mark);
    }

    void print() const {
        cout << id << " - " << name << " average: " << fixed << setprecision(2) << average()
             << '\n';
    }
};

int Student::createdCount = 0;

int main() {
    Student student("Nora", 22501, {80, 87, 91});
    student.addMark(95);
    student.print();

    cout << "Name through getter: " << student.getName() << '\n';
    cout << "Students created: " << Student::createdCount << '\n';

    return 0;
}
