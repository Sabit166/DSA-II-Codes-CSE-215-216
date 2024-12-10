#include <bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int v,w;
    Edge(){}
    Edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};

vector<Edge>adj[100];

int main()
{
    int n,u,v,w;
    cout << "Enter number of Edges: \n";
    cin >> n;
    Edge e[n];
    int distance[n];
    vector<vector<int>>path(n);
    /*for(int i=0;i<n;i++)
    {
        cout << "\nEnter initial vertex: ";
        cin >> u;
        cout << "\nEnter Destination vertex: ";
        cin >> v;
        cout << "\nEnter Edge Weight: ";
        cin >> w;
        e[i]=Edge(v,w);
        adj[u].push_back(e[i]);
    }*/

   adj[0].push_back({1,5});
   adj[0].push_back({2,2});
   adj[1].push_back({3,3});
   adj[2].push_back({1,1});
   adj[2].push_back({4,10});
   adj[3].push_back({4,1});
   adj[3].push_back({5,6});
   adj[4].push_back({5,1});
   adj[4].push_back({2,1});
   for(int i=0;i<n;i++) distance[i]=INT_MAX;

    queue<int>qu;
    distance[0]=0;
    path[0]={0};
    qu.push(0);
    int temp;
    while(!qu.empty())
    {   
        temp=qu.front();
        qu.pop();
        for(auto &edge:adj[temp])
        {
            if(distance[temp]+edge.w<distance[edge.v])
            {
                distance[edge.v]=distance[temp]+edge.w;
                vector<int>v=path[temp];
                v.push_back(edge.v);
                path[edge.v]=v;
                qu.push(edge.v);
            }
        }
    }

    for(int i=0;i<6;i++)
    {
        cout << "Minimum distance from source to " << i << " is "<< distance[i] << endl << "Path: ";
        for(auto &it: path[i])
        {
            cout << it << ' ';
        }
        cout << endl;
    }
}