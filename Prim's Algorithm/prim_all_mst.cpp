#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, weight;
};

struct WeightedEdge {
    int weight;
    pair<int, int> edge;
    bool operator>(const WeightedEdge& other) const {
        return weight > other.weight;
    }
};

class Graph {
    int V;
    vector<vector<Edge>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void printAllMSTs() {
        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        priority_queue<WeightedEdge, vector<WeightedEdge>, greater<WeightedEdge>> pq;

        key[0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int u = pq.top().edge.second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (const auto &edge : adj[u]) {
                int v = edge.v;
                int weight = edge.weight;
                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], {u, v}});
                    parent[v] = u;
                }
            }
        }

        // Print the MST
        for (int i = 1; i < V; ++i) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << " : " << key[i] << endl;
            }
        }
        cout << "-------------------" << endl;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.printAllMSTs();

    return 0;
}