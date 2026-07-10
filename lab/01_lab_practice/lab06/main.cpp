#include <iostream>
#include "sortedtype.h"
#include "sortedtype.cpp"
#include "timestamp.h"

using namespace std;

void PrintIntegerList(SortedType<int>& list) {
    int value;

    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(value);
        cout << value << " ";
    }

    cout << endl;
}

void PrintSearchResult(
    SortedType<int>& list,
    int searchValue
) {
    bool found;

    list.Search(searchValue, found);

    if (found) {
        cout << "Item is found" << endl;
    }
    else {
        cout << "Item is not found" << endl;
    }
}

void PrintFullStatus(SortedType<int>& list) {
    if (list.IsFull()) {
        cout << "List is full" << endl;
    }
    else {
        cout << "List is not full" << endl;
    }
}

void PrintTimeList(SortedType<timeStamp>& list) {
    timeStamp value;

    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(value);
        value.Print();
    }
}

int main() {
    // Part 1: Sorted integer list
    cout << "SORTED INTEGER LIST" << endl;
    SortedType<int> numbers;

    // Insert four items: 5, 4, 2, 1.
    numbers.Insert(5);
    numbers.Insert(4);
    numbers.Insert(2);
    numbers.Insert(1);

    cout << "List: ";
    PrintIntegerList(numbers);

    numbers.Insert(7);
    numbers.Insert(12);
    cout << "List: ";
    PrintIntegerList(numbers);
    cout << "Search for 6: ";
    PrintSearchResult(numbers, 6);
    cout << "Search for 5: ";
    PrintSearchResult(numbers, 5);
    PrintFullStatus(numbers);
    // Delete 1.
    numbers.Delete(1);

    // Expected: 2 4 5 7
    cout << "After deleting 1: ";
    PrintIntegerList(numbers);

    // Delete 4.
    numbers.Delete(4);
    // Expected: 2 5 7

    cout << "After deleting 4: ";
    PrintIntegerList(numbers);
    // 16 is not present.
    numbers.Delete(16);

    // Part 2: Sorted timeStamp list

    cout << endl;
    cout << "SORTED TIMESTAMP LIST" << endl;
    SortedType<timeStamp> times;
    times.Insert(timeStamp(15, 34, 23));
    times.Insert(timeStamp(13, 13, 2));
    times.Insert(timeStamp(43, 45, 12));
    times.Insert(timeStamp(25, 36, 17));
    times.Insert(timeStamp(52, 2, 20));
    times.Delete(timeStamp(25, 36, 17));
    cout << "Times after deletion:" << endl;
    PrintTimeList(times);

    return 0;
}
