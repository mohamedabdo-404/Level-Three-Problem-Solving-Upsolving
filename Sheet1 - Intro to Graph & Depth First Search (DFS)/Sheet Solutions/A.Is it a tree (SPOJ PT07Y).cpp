#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<ll>>adj(10005);
vector<bool>vis(10005);
bool hasCycle=false;
void dfs(int node,int p){//O(n+m)
  vis[node]=true;
  for(auto i:adj[node]){
    if(!vis[i])
     { 
      dfs(i,node);
     }
     else if(i!=p){
      hasCycle=true;
     }
  }
}
void solve(){
  ll n,m;
  cin>>n>>m;
  
  for (int i = 0; i < m; i++)//UnDirected
  {
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
 
    dfs(1,0);//O(n+m)
    bool f=true;
    for (int i = 1; i <= n; i++)
    {
      if(!vis[i]){
        f=false;
        break;
      }
    }
    if(f&&(!hasCycle)){
      cout<<"YES\n";
    }else{
    cout<<"NO\n";
    }
}
int main(){
    Fast
    ll T = 1;
    // cin >> T;
    // cin.ignore();
    while (T--){
        solve();
    }
}