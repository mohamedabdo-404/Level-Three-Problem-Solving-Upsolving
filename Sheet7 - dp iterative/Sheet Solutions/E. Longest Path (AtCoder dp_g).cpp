#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    int n,m; cin>>n>>m;
    vector<vector<int>>adj(n),radj(n);
    vector<int>indeg(n,0);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v; u--;v--;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++) if(!indeg[i]) q.push(i);
    vector<ll>dp(n,0);
    ll ans=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        ans=max(ans,dp[u]);
        for(int v:adj[u]){
            dp[v]=max(dp[v],dp[u]+1);
            if(--indeg[v]==0) q.push(v);
        }
    }
    cout<<ans<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
