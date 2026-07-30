#include <iostream>
#include <vector>

#include "queuetype.h"
#include "queuetype.cpp"

using namespace std;

template <class T>
void PrintQueue(QueueType<T>& queue) {
    QueueType<T> temporary;
    T value;

    while (!queue.IsEmpty()) {
        queue.Dequeue(value);
        temporary.Enqueue(value);
    }

    bool first = true;
    while (!temporary.IsEmpty()) {
        temporary.Dequeue(value);

        if (!first) {
            cout << ", ";
        }

        cout << value;
        first = false;
        queue.Enqueue(value);
    }

    cout << endl;
}

struct AmountState {
    int amount;
    int coinsUsed;
};

int MinimumCoins(const vector<int>& coinValues, int target) {
    if (target == 0) {
        return 0;
    }

    vector<bool> visited(target + 1, false);
    QueueType<AmountState> pending;
    AmountState start = {0, 0};
    pending.Enqueue(start);
    visited[0] = true;

    while (!pending.IsEmpty()) {
        AmountState current;
        pending.Dequeue(current);

        for (size_t i = 0; i < coinValues.size(); i++) {
            if (coinValues[i] <= 0) {
                continue;
            }

            int nextAmount = current.amount + coinValues[i];

            if (nextAmount == target) {
                return current.coinsUsed + 1;
            }

            if (nextAmount < target && !visited[nextAmount]) {
                visited[nextAmount] = true;
                AmountState next = {nextAmount, current.coinsUsed + 1};
                pending.Enqueue(next);
            }
        }
    }

    return -1;
}

void PrintCoinResult(const vector<int>& coins, int target) {
    cout << "Coins: {";

    for (size_t i = 0; i < coins.size(); i++) {
        cout << coins[i];
        if (i + 1 < coins.size()) {
            cout << ", ";
        }
    }

    cout << "}, target: " << target << endl;
    cout << "Minimum number of coins needed: "
         << MinimumCoins(coins, target)
         << endl;
}

int main() {
    cout << "LINKED-LIST QUEUE" << endl;
    cout << "-----------------" << endl;

    QueueType<int> queue;
    queue.Enqueue(5);
    queue.Enqueue(7);
    queue.Enqueue(4);
    queue.Enqueue(2);
    queue.Enqueue(6);

    cout << "Queue values: ";
    PrintQueue(queue);

    int removed;
    queue.Dequeue(removed);
    queue.Dequeue(removed);
    cout << "After two dequeues: ";
    PrintQueue(queue);

    cout << endl;
    cout << "MINIMUM COIN COUNT USING A QUEUE" << endl;
    cout << "--------------------------------" << endl;

    PrintCoinResult(vector<int>{2, 3, 5}, 11);
    PrintCoinResult(vector<int>{5, 20, 30}, 40);
    PrintCoinResult(vector<int>{2, 3, 5}, 200);

    return 0;
}
