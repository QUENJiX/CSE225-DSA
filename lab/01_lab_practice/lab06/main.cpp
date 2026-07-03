#include <iomanip>
#include <iostream>
#include "sortedtype.h"
#include "sortedtype.cpp"
using namespace std;

class timeStamp {
   private:
    int seconds;
    int minutes;
    int hours;

    int totalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

   public:
    timeStamp() {
        seconds = 0;
        minutes = 0;
        hours = 0;
    }

    timeStamp(int s, int m, int h) {
        seconds = s;
        minutes = m;
        hours = h;
    }

    bool operator==(const timeStamp& other) const {
        return totalSeconds() == other.totalSeconds();
    }

    bool operator<(const timeStamp& other) const {
        return totalSeconds() < other.totalSeconds();
    }

    bool operator>(const timeStamp& other) const {
        return totalSeconds() > other.totalSeconds();
    }

    void Print() const {
        cout << setw(2) << setfill('0') << seconds << ": "
             << setw(2) << minutes << ": "
             << setw(2) << hours << setfill(' ') << endl;
    }
};

void PrintIntegerList(SortedType<int>& list) {
    int item;
    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        cout << item << " ";
    }
    cout << endl;
}

void PrintTimeList(SortedType<timeStamp>& list) {
    timeStamp item;
    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        item.Print();
    }
}

void PrintSearchResult(SortedType<int>& list, int item) {
    bool found;
    list.Search(item, found);

    if (found) {
        cout << "Item is found" << endl;
    } else {
        cout << "Item is not found" << endl;
    }
}

void PrintFullStatus(SortedType<int>& list) {
    if (list.IsFull()) {
        cout << "List is full" << endl;
    } else {
        cout << "List is not full" << endl;
    }
}

int main() {
    SortedType<int> numbers;

    numbers.Insert(5);
    numbers.Insert(4);
    numbers.Insert(2);
    numbers.Insert(1);
    PrintIntegerList(numbers);

    numbers.Insert(7);
    numbers.Insert(12);
    PrintIntegerList(numbers);

    PrintSearchResult(numbers, 6);
    PrintSearchResult(numbers, 5);
    PrintFullStatus(numbers);

    numbers.Delete(1);
    PrintIntegerList(numbers);

    numbers.Delete(4);
    PrintIntegerList(numbers);

    numbers.Delete(16);

    cout << endl;

    SortedType<timeStamp> times;
    times.Insert(timeStamp(15, 34, 23));
    times.Insert(timeStamp(13, 13, 2));
    times.Insert(timeStamp(43, 45, 12));
    times.Insert(timeStamp(25, 36, 17));
    times.Insert(timeStamp(52, 2, 20));

    times.Delete(timeStamp(25, 36, 17));
    PrintTimeList(times);

    return 0;
}
