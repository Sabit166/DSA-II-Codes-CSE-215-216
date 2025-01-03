#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int>parent , size , rank;
    public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    int find_set(int u)
    {
        if(parent[u] == u) return u;

        return parent[u] = find_set(parent[u]);
    }

    void make_union(int u, int v)
    {
        if(u == v) return;
        u = find_set(u);
        v = find_set(v);

        parent[v] = u;
    }

    void union_by_rank(int u, int v)
    {
        if(u == v) return;

        u = find_set(u);
        v = find_set(v);

        if(rank[v] > rank[u]) swap(u, v);

        parent[v] = u;

        if(u == v) rank[u]++;
    }

    void union_by_size(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);

        if(u == v) return;

        if(size[v] > size[u]) swap(u, v);
        parent[v] = u;
        size[u]+=size[v];
    }
};

int main()
{
    DSU dsu(5);
    dsu.make_union(0, 1);
    dsu.make_union(1, 2);
    dsu.make_union(3, 4);
    cout << dsu.find_set(0) << endl;
    cout << dsu.find_set(1) << endl;
    cout << dsu.find_set(2) << endl;
    cout << dsu.find_set(3) << endl;
    cout << dsu.find_set(4) << endl;
    return 0;
}