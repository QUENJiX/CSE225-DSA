#include <algorithm>
#include <iostream>
#include <vector>

#include "unsortedtype.h"
#include "unsortedtype.cpp"

using namespace std;

void PrintList(UnsortedType<int>& list) {
    int value;
    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(value);
        cout << value;

        if (i + 1 < list.Length()) {
            cout << " ";
        }
    }

    cout << endl;
}

void MergeInLinearTime(
    UnsortedType<int>& first,
    UnsortedType<int>& second,
    UnsortedType<int>& merged
) {
    vector<int> firstValues;
    int value;

    first.Reset();
    for (int i = 0; i < first.Length(); i++) {
        first.GetNext(value);
        firstValues.push_back(value);
    }

    // Insert in reverse so the first list keeps its linked-list order.
    for (vector<int>::reverse_iterator it = firstValues.rbegin();
         it != firstValues.rend();
         ++it) {
        merged.Insert(*it);
    }

    // Head insertion reverses the second list and places it before the first.
    second.Reset();
    for (int i = 0; i < second.Length(); i++) {
        second.GetNext(value);
        merged.Insert(value);
    }
}

void SortUniqueAscending(
    UnsortedType<int>& source,
    UnsortedType<int>& sorted
) {
    if (source.Length() == 0) {
        return;
    }

    vector<int> values;
    int value;
    source.Reset();

    for (int i = 0; i < source.Length(); i++) {
        source.GetNext(value);
        values.push_back(value);
    }

    int minimum = *min_element(values.begin(), values.end());
    int maximum = *max_element(values.begin(), values.end());
    vector<bool> present(maximum - minimum + 1, false);

    for (size_t i = 0; i < values.size(); i++) {
        present[values[i] - minimum] = true;
    }

    // Inserting from largest to smallest makes the head-first list ascending.
    for (long long current = maximum; current >= minimum; current--) {
        if (present[static_cast<int>(current) - minimum]) {
            sorted.Insert(static_cast<int>(current));
        }
    }
}

int main() {
    cout << "BASIC LINKED UNSORTED LIST" << endl;
    cout << "--------------------------" << endl;

    UnsortedType<int> numbers;
    numbers.Insert(5);
    numbers.Insert(7);
    numbers.Insert(6);
    numbers.Insert(9);

    cout << "After inserting 5, 7, 6, 9: ";
    PrintList(numbers);

    numbers.Insert(1);
    cout << "After inserting 1: ";
    PrintList(numbers);

    numbers.Delete(5);
    cout << "After deleting 5: ";
    PrintList(numbers);

    numbers.Delete(1);
    cout << "After deleting 1: ";
    PrintList(numbers);

    numbers.Delete(6);
    cout << "After deleting 6: ";
    PrintList(numbers);

    numbers.Delete(16);

    cout << endl;
    cout << "MERGE, REMOVE DUPLICATES, AND SORT" << endl;
    cout << "----------------------------------" << endl;

    const int firstInput[] = {
        10, 1, 5, 6, 10, 14, 20, 25, 31, 38, 40
    };
    const int secondInput[] = {
        12, 2, 4, 7, 9, 16, 19, 23, 24, 32, 35, 36, 42
    };

    UnsortedType<int> first;
    UnsortedType<int> second;

    for (size_t i = 0; i < sizeof(firstInput) / sizeof(firstInput[0]); i++) {
        first.Insert(firstInput[i]);
    }

    for (size_t i = 0; i < sizeof(secondInput) / sizeof(secondInput[0]); i++) {
        second.Insert(secondInput[i]);
    }

    UnsortedType<int> merged;
    MergeInLinearTime(first, second, merged);
    cout << "Merged list (unsorted): ";
    PrintList(merged);

    UnsortedType<int> sorted;
    SortUniqueAscending(merged, sorted);
    cout << "Sorted list (ascending): ";
    PrintList(sorted);

    return 0;
}
