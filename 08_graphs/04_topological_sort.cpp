#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(const vector<vector<int>>& graph) {
    int n = static_cast<int>(graph.size());
    vector<int> indegree(n, 0);

    for (int node = 0; node < n; ++node) {
        for (int neighbor : graph[node]) {
            ++indegree[neighbor];
        }
    }

    queue<int> ready;
    for (int node = 0; node < n; ++node) {
        if (indegree[node] == 0) {
            ready.push(node);
        }
    }

    vector<int> order;
    while (!ready.empty()) {
        int node = ready.front();
        ready.pop();
        order.push_back(node);

        for (int neighbor : graph[node]) {
            --indegree[neighbor];
            if (indegree[neighbor] == 0) {
                ready.push(neighbor);
            }
        }
    }

    return order;
}

int main() {
    vector<vector<int>> graph(6);
    graph[5] = {2, 0};
    graph[4] = {0, 1};
    graph[2] = {3};
    graph[3] = {1};

    vector<int> order = topologicalSort(graph);

    cout << "Topological order: ";
    for (int node : order) {
        cout << node << ' ';
    }
    cout << '\n';

    if (order.size() != graph.size()) {
        cout << "Cycle detected.\n";
    }

    return 0;
}

