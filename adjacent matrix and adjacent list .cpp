#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices; 
    vector<vector<int>> adjMatrix; 
    vector<vector<int>> adjList; 

public:

    Graph(int n) {
        vertices = n;
        adjMatrix.resize(vertices, vector<int>(vertices, 0)); 
        adjList.resize(vertices); 
    }

    void addEdge(int u, int v) {
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            cout << "Invalid vertices" << endl;
            return;
        }
        
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cout << "Enter the edge (u v): ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayAdjList();

    return 0;
}
