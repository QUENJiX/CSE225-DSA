#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count = 5;
    long long population = 170000000LL;
    double average = 87.4567;
    char grade = 'A';
    bool passed = true;
    string course = "CSE225";

    cout << "Course: " << course << '\n';
    cout << "Count: " << count << '\n';
    cout << "Population: " << population << '\n';
    cout << fixed << setprecision(2) << "Average: " << average << '\n';
    cout << "Grade: " << grade << '\n';
    cout << boolalpha << "Passed: " << passed << '\n';

    istringstream sampleInput("Nafis 21\nData Structures and Algorithms\n");
    string name;
    int age;
    sampleInput >> name >> age;

    string title;
    sampleInput.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(sampleInput, title);

    cout << "\nSample parsed input:\n";
    cout << name << " is " << age << " and is studying " << title << ".\n";

    return 0;
}

