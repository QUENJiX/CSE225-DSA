#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> values = {5, 1, 9, 3, 7};

    priority_queue<int> maxHeap;
    for (int value : values) {
        maxHeap.push(value);
    }

    cout << "Max heap order: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << ' ';
        maxHeap.pop();
    }
    cout << '\n';

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int value : values) {
        minHeap.push(value);
    }

    cout << "Min heap order: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << ' ';
        minHeap.pop();
    }
    cout << '\n';

    vector<int> heapVector = values;
    make_heap(heapVector.begin(), heapVector.end());
    heapVector.push_back(10);
    push_heap(heapVector.begin(), heapVector.end());

    cout << "Manual heap top after pushing 10: " << heapVector.front() << '\n';

    return 0;
}

