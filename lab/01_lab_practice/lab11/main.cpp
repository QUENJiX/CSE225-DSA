#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "stacktype.h"
#include "stacktype.cpp"

using namespace std;

bool IsOperator(char token) {
    return token == '+' || token == '-' || token == '*' || token == '/';
}

int Precedence(char operation) {
    if (operation == '*' || operation == '/') {
        return 2;
    }

    if (operation == '+' || operation == '-') {
        return 1;
    }

    return 0;
}

void AppendToken(ostringstream& output, const string& token) {
    if (output.tellp() > 0) {
        output << ' ';
    }

    output << token;
}

bool InfixToPostfix(const string& infix, string& postfix) {
    StackType<char> operations;
    ostringstream output;
    bool expectOperand = true;
    bool sawToken = false;
    int openParentheses = 0;

    for (size_t i = 0; i < infix.length();) {
        char token = infix[i];

        if (isspace(static_cast<unsigned char>(token))) {
            i++;
            continue;
        }

        if (isdigit(static_cast<unsigned char>(token))) {
            if (!expectOperand) {
                return false;
            }

            size_t start = i;
            while (i < infix.length() &&
                   isdigit(static_cast<unsigned char>(infix[i]))) {
                i++;
            }

            AppendToken(output, infix.substr(start, i - start));
            expectOperand = false;
            sawToken = true;
            continue;
        }

        if (token == '(') {
            if (!expectOperand) {
                return false;
            }

            operations.Push(token);
            openParentheses++;
            sawToken = true;
            i++;
            continue;
        }

        if (token == ')') {
            if (expectOperand || openParentheses == 0) {
                return false;
            }

            while (!operations.IsEmpty() && operations.Top() != '(') {
                AppendToken(output, string(1, operations.Top()));
                operations.Pop();
            }

            if (operations.IsEmpty()) {
                return false;
            }

            operations.Pop();
            openParentheses--;
            expectOperand = false;
            i++;
            continue;
        }

        if (IsOperator(token)) {
            if (expectOperand) {
                return false;
            }

            while (!operations.IsEmpty() &&
                   operations.Top() != '(' &&
                   Precedence(operations.Top()) >= Precedence(token)) {
                AppendToken(output, string(1, operations.Top()));
                operations.Pop();
            }

            operations.Push(token);
            expectOperand = true;
            i++;
            continue;
        }

        return false;
    }

    if (!sawToken || expectOperand || openParentheses != 0) {
        return false;
    }

    while (!operations.IsEmpty()) {
        if (operations.Top() == '(') {
            return false;
        }

        AppendToken(output, string(1, operations.Top()));
        operations.Pop();
    }

    postfix = output.str();
    return true;
}

bool IsNumberToken(const string& token) {
    if (token.empty()) {
        return false;
    }

    for (size_t i = 0; i < token.length(); i++) {
        if (!isdigit(static_cast<unsigned char>(token[i]))) {
            return false;
        }
    }

    return true;
}

bool EvaluatePostfix(const string& postfix, double& result) {
    StackType<double> values;
    istringstream input(postfix);
    string token;
    int valueCount = 0;

    while (input >> token) {
        if (IsNumberToken(token)) {
            values.Push(stod(token));
            valueCount++;
            continue;
        }

        if (token.length() != 1 || !IsOperator(token[0]) || valueCount < 2) {
            return false;
        }

        double right = values.Top();
        values.Pop();
        double left = values.Top();
        values.Pop();
        double combined;

        switch (token[0]) {
        case '+':
            combined = left + right;
            break;
        case '-':
            combined = left - right;
            break;
        case '*':
            combined = left * right;
            break;
        case '/':
            if (right == 0.0) {
                return false;
            }
            combined = left / right;
            break;
        default:
            return false;
        }

        values.Push(combined);
        valueCount--;
    }

    if (valueCount != 1 || values.IsEmpty()) {
        return false;
    }

    result = values.Top();
    return isfinite(result);
}

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

void ProcessExpression(const string& infix) {
    string postfix;
    double result;

    cout << "Infix: " << infix << endl;

    if (!InfixToPostfix(infix, postfix) ||
        !EvaluatePostfix(postfix, result)) {
        cout << "Invalid Expression" << endl;
        return;
    }

    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << setprecision(12) << result << endl;
}

int main() {
    cout << "LINKED-LIST STACK" << endl;
    cout << "-----------------" << endl;

    StackType<int> stack;
    stack.Push(5);
    stack.Push(7);
    stack.Push(4);
    stack.Push(2);

    cout << "Stack values: ";
    PrintStackBottomToTop(stack);

    stack.Push(3);
    cout << "After pushing 3: ";
    PrintStackBottomToTop(stack);

    stack.Pop();
    stack.Pop();
    cout << "Top after two pops: " << stack.Top() << endl;

    cout << endl;
    cout << "INFIX TO POSTFIX AND EVALUATION" << endl;
    cout << "--------------------------------" << endl;

    const string expressions[] = {
        "10 + 3 * 5 / (16 - 4)",
        "(5 + 3) * 12 / 3",
        "3 + 4 / (2 - 3) * / 5",
        "7 / 5 + (4 - (2) * 3"
    };

    for (size_t i = 0; i < sizeof(expressions) / sizeof(expressions[0]); i++) {
        ProcessExpression(expressions[i]);
        if (i + 1 < sizeof(expressions) / sizeof(expressions[0])) {
            cout << endl;
        }
    }

    return 0;
}
