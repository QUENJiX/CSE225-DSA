#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int weight;
    int from;
    int to;
};

struct DSU {
    vector<int> parent;
    vector<int> size;

    explicit DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return false;
        }

        if (size[a] < size[b]) {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](const Edge& left, const Edge& right) {
        return left.weight < right.weight;
    });

    DSU dsu(n);
    int total = 0;

    for (const Edge& edge : edges) {
        if (dsu.unite(edge.from, edge.to)) {
            total += edge.weight;
            cout << "Take edge " << edge.from << "-" << edge.to << " weight " << edge.weight
                 << '\n';
        }
    }

    return total;
}

int main() {
    vector<Edge> edges = {
        {4, 0, 1},
        {2, 0, 2},
        {1, 1, 2},
        {5, 1, 3},
        {8, 2, 3},
        {10, 2, 4},
        {2, 3, 4},
    };

    cout << "MST total weight: " << kruskal(5, edges) << '\n';
    return 0;
}

