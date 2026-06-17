#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    string name;
    int marks;
};

int main() {
    vector<Student> students = {
        {22501, "Ari", 87},
        {22502, "Mira", 94},
        {22503, "Tuhin", 78},
        {22504, "Nora", 91},
    };

    unordered_map<int, Student> byId;
    for (const Student& student : students) {
        byId[student.id] = student;
    }

    cout << "Fast lookup by student ID:\n";
    int searchId = 22502;
    if (byId.count(searchId) > 0) {
        cout << byId[searchId].name << " has marks " << byId[searchId].marks << '\n';
    }

    priority_queue<pair<int, string>> topStudents;
    for (const Student& student : students) {
        topStudents.push({student.marks, student.name});
    }

    cout << "\nTop 2 students by marks:\n";
    for (int count = 0; count < 2 && !topStudents.empty(); ++count) {
        auto [marks, name] = topStudents.top();
        topStudents.pop();
        cout << name << " -> " << marks << '\n';
    }

    queue<string> advisingLine;
    advisingLine.push("Ari");
    advisingLine.push("Mira");
    advisingLine.push("Tuhin");

    cout << "\nAdvising queue:\n";
    while (!advisingLine.empty()) {
        cout << "Serve " << advisingLine.front() << '\n';
        advisingLine.pop();
    }

    vector<vector<int>> prerequisiteGraph(4);
    prerequisiteGraph[0].push_back(1);
    prerequisiteGraph[1].push_back(2);
    prerequisiteGraph[1].push_back(3);

    cout << "\nPrerequisite graph adjacency list:\n";
    for (int course = 0; course < static_cast<int>(prerequisiteGraph.size()); ++course) {
        cout << course << ": ";
        for (int nextCourse : prerequisiteGraph[course]) {
            cout << nextCourse << ' ';
        }
        cout << '\n';
    }

    cout << "\nDomain feature -> structure choice:\n";
    cout << "ID lookup -> unordered_map\n";
    cout << "Repeated top marks -> priority_queue\n";
    cout << "First-come advising -> queue\n";
    cout << "Prerequisite relationships -> graph\n";

    return 0;
}
