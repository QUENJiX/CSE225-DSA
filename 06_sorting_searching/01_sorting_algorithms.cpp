#include <bits/stdc++.h>
using namespace std;

void print(const vector<int>& values) {
    for (int value : values) {
        cout << value << ' ';
    }
    cout << '\n';
}

vector<int> insertionSort(vector<int> values) {
    for (int i = 1; i < static_cast<int>(values.size()); ++i) {
        int key = values[i];
        int j = i - 1;
        while (j >= 0 && values[j] > key) {
            values[j + 1] = values[j];
            --j;
        }
        values[j + 1] = key;
    }
    return values;
}

void mergeSort(vector<int>& values, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(values, left, mid);
    mergeSort(values, mid + 1, right);

    vector<int> merged;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (values[i] <= values[j]) {
            merged.push_back(values[i++]);
        } else {
            merged.push_back(values[j++]);
        }
    }

    while (i <= mid) {
        merged.push_back(values[i++]);
    }
    while (j <= right) {
        merged.push_back(values[j++]);
    }

    for (int k = 0; k < static_cast<int>(merged.size()); ++k) {
        values[left + k] = merged[k];
    }
}

int partition(vector<int>& values, int low, int high) {
    int pivot = values[high];
    int smaller = low - 1;

    for (int i = low; i < high; ++i) {
        if (values[i] <= pivot) {
            ++smaller;
            swap(values[smaller], values[i]);
        }
    }

    swap(values[smaller + 1], values[high]);
    return smaller + 1;
}

void quickSort(vector<int>& values, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = partition(values, low, high);
    quickSort(values, low, pivotIndex - 1);
    quickSort(values, pivotIndex + 1, high);
}

int main() {
    vector<int> values = {8, 3, 5, 1, 9, 2};

    cout << "Insertion sort: ";
    print(insertionSort(values));

    vector<int> merged = values;
    mergeSort(merged, 0, static_cast<int>(merged.size()) - 1);
    cout << "Merge sort: ";
    print(merged);

    vector<int> quick = values;
    quickSort(quick, 0, static_cast<int>(quick.size()) - 1);
    cout << "Quick sort: ";
    print(quick);

    sort(values.begin(), values.end());
    cout << "STL sort: ";
    print(values);

    return 0;
}

