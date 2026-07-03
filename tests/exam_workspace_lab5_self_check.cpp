#include <cassert>
#include <string>
#include "unsortedtype.h"
#include "unsortedtype.cpp"
using namespace std;

class ExamStudent {
   private:
    int id;
    string name;

   public:
    ExamStudent() {
        id = 0;
        name = "";
    }

    ExamStudent(int studentId, string studentName) {
        id = studentId;
        name = studentName;
    }

    bool operator==(const ExamStudent& other) const {
        return id == other.id;
    }
};

int main() {
    UnsortedType<int> numbers;
    assert(numbers.Length() == 0);
    assert(numbers.IsEmpty());

    numbers.Insert(5);
    numbers.Insert(7);
    numbers.Insert(6);
    numbers.Insert(9);
    numbers.Insert(1);
    numbers.Insert(12);

    assert(numbers.Length() == 5);
    assert(numbers.IsFull());

    bool found;
    numbers.Search(6, found);
    assert(found);
    numbers.Search(10, found);
    assert(!found);

    numbers.Delete(7);
    assert(numbers.Length() == 4);
    numbers.Search(7, found);
    assert(!found);
    numbers.Search(1, found);
    assert(found);

    int item;
    numbers.Reset();
    for (int i = 0; i < numbers.Length(); i++) {
        numbers.GetNext(item);
    }

    numbers.MakeEmpty();
    assert(numbers.Length() == 0);
    assert(numbers.IsEmpty());

    UnsortedType<ExamStudent> students;
    students.Insert(ExamStudent(10, "A"));
    students.Insert(ExamStudent(20, "B"));
    students.Insert(ExamStudent(30, "C"));
    students.Delete(ExamStudent(20, ""));

    students.Search(ExamStudent(20, ""), found);
    assert(!found);
    students.Search(ExamStudent(30, ""), found);
    assert(found);

    return 0;
}
