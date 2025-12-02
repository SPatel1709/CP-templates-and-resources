 #include <bits/stdc++.h>

using namespace std;
using ll=long long;

void djikstra(int source, int n, vector<ll> &dist, vector<ll> &parent, vector<pair<int,ll>> adj[])
{
    dist.assign(n,INT_MAX);
    parent.assign(n,-1);

    dist[source]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push({0,source});
    while(q.empty()==false){
        pair<ll,int> curr=q.top();
        q.pop();
        int v= curr.second;
        ll distance_v=curr.first;

        if(distance_v!=dist[v])
        {
            continue;
        }

        for(auto edge:adj[v])
        {
            if(dist[v]+edge.second<dist[edge.first])
            {
                dist[edge.first]=dist[v]+edge.second;
                parent[edge.first]=v;
                q.push({dist[edge.first],edge.first});
            }
        }
    }
}

//this bellmanford first converts the adj matrix to list of egdes u,v weight so if already given that way no need to convert to e
void BellmanFord(int n,int src, vector<pair<int,ll>> edges[],vector<ll> &dist,set<int> &negCycle)
{
    fill(dist.begin(),dist.end(),INT_MAX);
    dist[src]=0;
    vector<pair<ll,pair<int,int>>> e;
    vector<int> parent(n,-1);
    for(int i=0;i<n;i++)
    {
        for(auto j:edges[i])
        {
            e.push_back({j.second,{i,j.first}});
        }
    }

    bool changed=true;
    for(int i=0; i<n-1; i++)
    {
        changed=false;
        for(auto j:e)
        {
            if(dist[j.second.second]>dist[j.second.first]+j.first)
        { 
            parent[j.second.second]=j.second.first;
            dist[j.second.second]=dist[j.second.first]+j.first;
            changed=true;
        }
        }
        if(!changed) break;
    }


    for(int i=0; i<n;i++)
    {
        for(auto j:e)
        {
            if(dist[j.second.second]>dist[j.second.first]+j.first)
            {
                dist[j.second.second]= dist[j.second.first]+j.first;
                negCycle.insert(j.second.second);
            }
        }
    }
}


//This only returns sum if you want the edges to be returned then change to pq to store wt,u,par
int Prim(int V,vector<vector<pair<int,int>>> &adj)
{
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited(V,false);

    pq.push({0,0});
    int sum=0;
    while(pq.empty()==false)
    {
        int node=pq.top().second;
        int weight=pq.top().first;
        pq.pop();

        if(visited[node]) continue;

        visited[node]=1;
        sum+=weight;

        for(auto &x:adj[node])
        {
            int child=x.first;
            int wt=x.second;
            if(visited[child]) continue;
            pq.push({wt,child});
        }

    }

    return sum;
}