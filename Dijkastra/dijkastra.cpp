#include <bits/stdc++.h>
using namespace std;
#define iint long long

int n, m;
vector<bool> visited;

void dijkastra(vector<pair<int, int>> adj[], vector<int> &dist, int src)
{
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        visited[u] = true;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (!visited[v] && dist[v] > dist[u] + w )
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}

int main()
{
    cin >> n >> m;
    vector<pair<int, int>> adj[n+1];
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INT_MAX);

    dijkastra(adj, dist, 1);
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