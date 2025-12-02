#include <bits/stdc++.h>

using namespace std;

using ll=long long;


//this is DSU by rank and size
class DisjointSet{
    vector<int> rank,parent,size;

    public:

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int findPar(int node)
    {
        if(node==parent[node]) return node;
        
        return parent[node]=findPar(parent[node]);
    }

   void unionByRank(int u, int v) {
    u = findPar(u);
    v = findPar(v);

    if(u == v) return;
    
    if(rank[u] < rank[v]) 
        swap(u, v);

    parent[v] = u;

    if(rank[u] == rank[v]) 
        rank[u]++;
}
    void unionBySize(int u,int v)
    {
        int parent_u=findPar(u);
        int parent_v=findPar(v);

        if(parent_u==parent_v) return;

        if(size[parent_u]<size[parent_v])
        {
            parent[parent_u]=parent_v;
            size[parent_v]+=size[parent_u];
        }
        else{
            parent[parent_v]=parent_u;
            size[parent_u]+=size[parent_v];
        }
    }
};


//This is DSU by size
