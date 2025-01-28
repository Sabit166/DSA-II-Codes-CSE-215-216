#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        //adj[v].push_back({u, w});
    }
    int src = 0;
    vector<int> key(n, LLONG_MAX);
    vector<int> parent(n, -1);
    vector<bool> mst(n, false);
    key[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\n";
    }
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