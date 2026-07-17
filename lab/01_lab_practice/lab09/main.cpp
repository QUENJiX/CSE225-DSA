#include <iostream>
#include <string>

#include "stacktype.h"
#include "stacktype.cpp"

using namespace std;

void PrintStackBottomToTop(StackType<int>& stack) {
    StackType<int> reversed;

    while (!stack.IsEmpty()) {
        reversed.Push(stack.Top());
        stack.Pop();
    }

    bool first = true;
    while (!reversed.IsEmpty()) {
        int value = reversed.Top();
        reversed.Pop();

        if (!first) {
            cout << ", ";
        }

        cout << value;
        first = false;
        stack.Push(value);
    }

    cout << endl;
}

bool IsBalanced(const string& expression) {
    StackType<char> openings;

    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            openings.Push(expression[i]);
        }
        else if (expression[i] == ')') {
            if (openings.IsEmpty()) {
                return false;
            }

            openings.Pop();
        }
    }

    return openings.IsEmpty();
}

void PrintEmptyStatus(StackType<int>& stack) {
    cout << (stack.IsEmpty() ? "Stack is Empty" : "Stack is not Empty")
         << endl;
}

void PrintFullStatus(StackType<int>& stack) {
    cout << (stack.IsFull() ? "Stack is full" : "Stack is not full")
         << endl;
}

int main() {
    cout << "ARRAY-BASED STACK" << endl;
    cout << "-----------------" << endl;

    StackType<int> stack;
    PrintEmptyStatus(stack);

    stack.Push(5);
    stack.Push(7);
    stack.Push(4);
    stack.Push(2);
    PrintEmptyStatus(stack);
    PrintFullStatus(stack);

    cout << "Stack values: ";
    PrintStackBottomToTop(stack);

    stack.Push(3);
    cout << "After pushing 3: ";
    PrintStackBottomToTop(stack);
    PrintFullStatus(stack);

    stack.Pop();
    stack.Pop();
    cout << "Top after two pops: " << stack.Top() << endl;

    cout << endl;
    cout << "BALANCED PARENTHESES" << endl;
    cout << "--------------------" << endl;

    const string expressions[] = {
        "()",
        "(())()(()())()",
        "(())()((()",
        "(())))((()",
        "(())))))))"
    };

    for (size_t i = 0; i < sizeof(expressions) / sizeof(expressions[0]); i++) {
        cout << expressions[i] << " -> "
             << (IsBalanced(expressions[i]) ? "Balanced" : "Not Balanced")
             << endl;
    }

    return 0;
}
