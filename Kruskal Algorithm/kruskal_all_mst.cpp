#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> parent, rank_set;

void make_set(int v) {
    parent[v] = v;
    rank_set[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_set[a] < rank_set[b])
            swap(a, b);
        parent[b] = a;
        if (rank_set[a] == rank_set[b])
            rank_set[a]++;
        return true;
    }
    return false;
}

void backtrack(int index, int edges_used, int vertices, vector<Edge>& edges, vector<Edge>& mst, vector<vector<Edge>>& all_msts) 
{
    if (edges_used == vertices - 1) {
        // A valid MST is formed when the number of edges used is equal to n - 1
        all_msts.push_back(mst);
        return;
    }
    if (index == edges.size())
        return;

    Edge edge = edges[index];
    if (union_sets(edge.u, edge.v)) {
        mst.push_back(edge);
        backtrack(index + 1, edges_used + 1, vertices, edges, mst, all_msts);
        mst.pop_back();
        parent[edge.u] = edge.u;
        parent[edge.v] = edge.v;
    }
    backtrack(index + 1, edges_used, vertices, edges, mst, all_msts);
}

void kruskal_all_mst(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    vector<Edge> mst;
    vector<vector<Edge>> all_msts;

    for (int i = 0; i < n; i++)
        make_set(i);

    backtrack(0, 0 ,n ,  edges, mst, all_msts);

    for (auto& mst : all_msts) {
        for (auto& edge : mst) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
        }
        cout << "-----------------" << endl;
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    parent.resize(n);
    rank_set.resize(n);

    kruskal_all_mst(n, edges);

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