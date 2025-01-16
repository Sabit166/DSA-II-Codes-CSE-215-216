#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<bool> visited;

void dijkastra(vector<pair<int, int>> adj[], vector<int>&dist, int src) {
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if(!visited[v] && dist[v] > dist[u] + w) {
                visited[v] = true;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}

signed main() {
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    visited.resize(n, false);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        //adj[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX);

    dijkastra(adj, dist, 0);
    return 0;
}

 /***************************************************
  *          Crafted by: SABIT                      *
  *          Github: Sabit 166                      *
  *                                                 *
  * "Programs must be written for people to read,   *
  * and only incidentally for machines to execute." *
  * - Harold Abelson                                *
  ***************************************************/