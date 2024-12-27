#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &e) const {
        return weight < e.weight;
    }
};

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // Initially, each node is its own parent
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskal(int V, vector<Edge> &edges) {
    DisjointSet ds(V);
    vector<Edge> mst;  

    sort(edges.begin(), edges.end());

    for (const auto &e : edges) {
        int u = e.u;
        int v = e.v;

        // If u and v are in different sets, include this edge in the MST
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(e);
            ds.unite(u, v);
        }
    }

 
    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    int totalWeight = 0;
    for (const auto &e : mst) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
        totalWeight += e.weight;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(V, edges);

    return 0;
}
