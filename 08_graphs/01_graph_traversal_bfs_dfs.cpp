#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 1;
    cout << node << ' ';

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

vector<int> bfsDistances(int start, const vector<vector<int>>& graph) {
    vector<int> distance(graph.size(), -1);
    queue<int> pending;

    distance[start] = 0;
    pending.push(start);

    while (!pending.empty()) {
        int node = pending.front();
        pending.pop();

        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                pending.push(neighbor);
            }
        }
    }

    return distance;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 3, 4},
        {1, 2},
        {2},
    };

    vector<int> visited(graph.size(), 0);
    cout << "DFS from 0: ";
    dfs(0, graph, visited);
    cout << '\n';

    vector<int> distance = bfsDistances(0, graph);
    cout << "BFS distances from 0: ";
    for (int value : distance) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}

