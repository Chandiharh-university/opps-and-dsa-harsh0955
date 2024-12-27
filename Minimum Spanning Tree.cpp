#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    
    bool operator < (const Edge& e) const {
        return weight < e.weight;
    }
};

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
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

void kruskalMST(int V, vector<Edge>& edges) {
    
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    vector<Edge> mst; 
    
    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        if (ds.find(u) != ds.find(v)) {
            ds.unite(u, v);
            mst.push_back(edge);  // Add to MST
        }
    }

    cout << "Minimum Spanning Tree (MST):" << endl;
    int totalWeight = 0;
    for (const auto& edge : mst) {
        cout << "Edge (" << edge.u << ", " << edge.v << ") with weight " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;
    
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskalMST(V, edges);

    return 0;
}
