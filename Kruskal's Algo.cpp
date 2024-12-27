#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list (vertex, weight)

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void dijkstra(int start);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight)); // Add edge u -> v with weight
}

void Graph::dijkstra(int start) {
    vector<int> dist(V, INT_MAX); // Distance from start to each vertex
    dist[start] = 0; // Distance to the start vertex is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    pq.push(make_pair(0, start)); // Push the start vertex

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop();

        // Explore all adjacent vertices
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v)); // Push the updated distance
            }
        }
    }

    // Print the shortest distances from the start vertex
    cout << "Vertex\tDistance from Source (" << start << ")\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
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

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    g.dijkstra(start);

    return 0;
}