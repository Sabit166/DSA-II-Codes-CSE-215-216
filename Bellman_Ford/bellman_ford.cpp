#include <bits/stdc++.h>
using namespace std;
#define int long long

void Bellman_Ford(vector<vector<int>> &edges, int n, int src, vector<int> &dist)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    for (auto e : edges)
    {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if (dist[v] > dist[u] + w)
        {
            cout << "Negative cycle found";
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int src;
    cin >> src;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    Bellman_Ford(edges, n, src, dist);
}

 /***************************************************
  *          Crafted by: SABIT                      *
  *          Github: Sabit 166                      *
  *                                                 *
  * "Programs must be written for people to read,   *
  * and only incidentally for machines to execute." *
  * - Harold Abelson                                *
  ***************************************************/