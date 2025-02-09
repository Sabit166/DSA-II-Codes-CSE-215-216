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

    void printMST() {
        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        priority_queue<WeightedEdge, vector<WeightedEdge>, greater<WeightedEdge>> pq;

        int src = 0;
        key[src] = 0;
        pq.push({0, {src, src}});

        while (!pq.empty()) {
            int u = pq.top().edge.second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto& edge : adj[u]) {
                int v = edge.v;
                int weight = edge.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], {u, v}});
                    parent[v] = u;
                }
            }
        }

        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.printMST();

    return 0;
}