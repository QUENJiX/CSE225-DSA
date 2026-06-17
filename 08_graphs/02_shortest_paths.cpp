#include <bits/stdc++.h>
using namespace std;

vector<int> unweightedShortestPath(int start, const vector<vector<int>>& graph) {
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

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    const int inf = 1e9;
    vector<int> distance(graph.size(), inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDistance, node] = pq.top();
        pq.pop();

        if (currentDistance != distance[node]) {
            continue;
        }

        for (auto [neighbor, weight] : graph[node]) {
            if (distance[node] + weight < distance[neighbor]) {
                distance[neighbor] = distance[node] + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }

    return distance;
}

int main() {
    vector<vector<int>> unweighted = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3},
    };

    cout << "BFS shortest edges from 0: ";
    for (int value : unweightedShortestPath(0, unweighted)) {
        cout << value << ' ';
    }
    cout << '\n';

    vector<vector<pair<int, int>>> weighted(5);
    auto addEdge = [&](int from, int to, int weight) {
        weighted[from].push_back({to, weight});
        weighted[to].push_back({from, weight});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(2, 1, 2);
    addEdge(1, 3, 1);
    addEdge(2, 3, 5);
    addEdge(3, 4, 3);

    cout << "Dijkstra distances from 0: ";
    for (int value : dijkstra(0, weighted)) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}

