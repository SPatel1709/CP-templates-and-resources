#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(ll node, ll par, vector<ll> adj[],vector<vector<ll>> &dp, vector<ll> &level,ll lev=0)
{
    dp[node][0]=par;
    level[node]=lev;
    for(ll i=1;i<=20;i++)
    {
        if(dp[node][i-1]!=-1)
        dp[node][i]=dp[dp[node][i-1]][i-1];
    }

    for(auto it: adj[node]){
        if(it!=par)
        {
            dfs(it,node,adj,dp,level,lev+1);
        }
    }
}


ll binarylifting(ll x,ll k,vector<vector<ll>> &dp)
{
    ll par=x;
    ll cnt=0;

    while(k){
        if(k&1)
        {
            par=dp[par][cnt];
        }
        k=k>>1;
        cnt++;
    }
    return par;
}

ll lca(ll a,ll b,vector<ll> &level,vector<vector<ll>> &dp)
{
    if(level[a]<level[b])
    {
        swap(a,b);
    }

    ll k = level[a]-level[b];
    a=binarylifting(a,k,dp);

    if(a==b)    return a;

    for(int i=20;i>=0;i--)
    {
        if(dp[a][i]!=dp[b][i])
        {
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}