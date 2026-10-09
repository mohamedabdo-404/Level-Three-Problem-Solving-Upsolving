#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<int>adj[100005];
int dp[100005];
int N,M;

int rec(int v){
    if(dp[v]!=-1) return dp[v];
    dp[v]=0;
    for(auto u:adj[v])
        dp[v]=max(dp[v],rec(u)+1);
    return dp[v];
}

void solve(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=N;i++) ans=max(ans,rec(i));
    cout<<ans<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}