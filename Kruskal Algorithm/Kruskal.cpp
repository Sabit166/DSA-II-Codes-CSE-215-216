#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const& other)
    {
        return weight < other.weight;
    }
    Edge(){}
    Edge(int u, int v, int weight)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

signed main() {
    int vertices, edges;

    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;
    vector<Edge> graph(edges);

    vector<Edge>result;
    vector<int>tree_id(vertices+1);
    for(int i=0;i<=vertices;i++) tree_id[i] = i;
    int u, v, w;
    int constant = 0;

    cout << "Enter the edges in the format (u, v, weight): ";
    for(int i=0; i<edges; i++)
    {
        cin >> u >> v >> w;
        graph[i] = Edge(u, v, w);
    }

    sort(graph.begin(), graph.end());

    for(Edge edge: graph)
    {
        if(tree_id[edge.u] == tree_id[edge.v]) continue;
        constant+=edge.weight;
        result.push_back(edge);

        int old_id = tree_id[edge.u], new_id = tree_id[edge.v];
        for(int i=1;i<=vertices;i++)
        {
            if(tree_id[i] == old_id) tree_id[i] = new_id;
        }
    }

    cout << "The minimum spanning tree is as follows\n";
    for(Edge edge: result)
    {
        cout << edge.u << ' ' << edge.v << ' ' << edge.weight << endl;
    }
}

 /***************************************************
  *          Crafted by: SABIT                      *
  *          Github: Sabit 166                      *
  *                                                 *
  * "Programs must be written for people to read,   *
  * and only incidentally for machines to execute." *
  * - Harold Abelson                                *
  ***************************************************/