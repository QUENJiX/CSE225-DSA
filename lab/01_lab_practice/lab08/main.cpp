#include <iostream>
#include <vector>

#include "sortedtype.h"
#include "sortedtype.cpp"

using namespace std;

void PrintList(SortedType<int>& list) {
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

void PrintSet(const string& name, SortedType<int>& set) {
    cout << name << " = {";
    int value;
    set.Reset();

    for (int i = 0; i < set.Length(); i++) {
        set.GetNext(value);
        cout << value;

        if (i + 1 < set.Length()) {
            cout << ",";
        }
    }

    cout << "}" << endl;
}

vector<int> ToVector(SortedType<int>& list) {
    vector<int> values;
    int value;
    list.Reset();

    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(value);
        values.push_back(value);
    }

    return values;
}

void BuildUnion(
    SortedType<int>& first,
    SortedType<int>& second,
    SortedType<int>& result
) {
    vector<int> left = ToVector(first);
    vector<int> right = ToVector(second);
    size_t i = 0;
    size_t j = 0;

    while (i < left.size() || j < right.size()) {
        int value;

        if (j == right.size() ||
            (i < left.size() && left[i] < right[j])) {
            value = left[i++];
        }
        else if (i == left.size() || right[j] < left[i]) {
            value = right[j++];
        }
        else {
            value = left[i];
            i++;
            j++;
        }

        bool found;
        result.Search(value, found);
        if (!found) {
            result.Insert(value);
        }
    }
}

void BuildIntersection(
    SortedType<int>& first,
    SortedType<int>& second,
    SortedType<int>& result
) {
    vector<int> left = ToVector(first);
    vector<int> right = ToVector(second);
    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            i++;
        }
        else if (right[j] < left[i]) {
            j++;
        }
        else {
            result.Insert(left[i]);
            i++;
            j++;
        }
    }
}

void PrintSearchResult(SortedType<int>& list, int value) {
    bool found;
    list.Search(value, found);
    cout << (found ? "Item is found" : "Item is not found") << endl;
}

int main() {
    cout << "BASIC LINKED SORTED LIST" << endl;
    cout << "------------------------" << endl;

    SortedType<int> numbers;
    numbers.Insert(5);
    numbers.Insert(4);
    numbers.Insert(2);
    numbers.Insert(1);

    cout << "After inserting 5, 4, 2, 1: ";
    PrintList(numbers);

    numbers.Insert(7);
    cout << "After inserting 7: ";
    PrintList(numbers);

    cout << "Search for 6: ";
    PrintSearchResult(numbers, 6);
    cout << "Search for 5: ";
    PrintSearchResult(numbers, 5);

    numbers.Delete(1);
    cout << "After deleting 1: ";
    PrintList(numbers);

    numbers.Delete(4);
    cout << "After deleting 4: ";
    PrintList(numbers);

    numbers.Delete(16);

    cout << endl;
    cout << "UNION AND INTERSECTION" << endl;
    cout << "----------------------" << endl;

    const int firstInput[] = {1, 2, 5, 6, 10, 14};
    const int secondInput[] = {3, 2, 4, 6, 9, 16, 19};
    SortedType<int> first;
    SortedType<int> second;

    for (size_t i = 0; i < sizeof(firstInput) / sizeof(firstInput[0]); i++) {
        first.Insert(firstInput[i]);
    }

    for (size_t i = 0; i < sizeof(secondInput) / sizeof(secondInput[0]); i++) {
        second.Insert(secondInput[i]);
    }

    PrintSet("T", first);
    PrintSet("F", second);

    SortedType<int> setUnion;
    BuildUnion(first, second, setUnion);
    PrintSet("T union F", setUnion);

    SortedType<int> intersection;
    BuildIntersection(first, second, intersection);
    PrintSet("T intersection F", intersection);

    return 0;
}
