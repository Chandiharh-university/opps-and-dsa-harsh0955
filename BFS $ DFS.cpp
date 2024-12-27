#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adjMatrix; 

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void primMST();
};

Graph::Graph(int V) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, INT_MAX)); 
    for (int i = 0; i < V; i++) {
        adjMatrix[i][i] = 0;
    }
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight; 
    adjMatrix[v][u] = weight; 
}

void Graph::primMST() {
    vector<int> parent(V, -1); 
    vector<int> key(V, INT_MAX); 
    vector<bool> inMST(V, false); 
    
    key[0] = 0; 
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        inMST[minIndex] = true;

        for (int v = 0; v < V; v++) {
            if (adjMatrix[minIndex][v] != INT_MAX && !inMST[v] && adjMatrix[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = adjMatrix[minIndex][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (u v weight) format:\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    g.primMST();

    return 0;
}