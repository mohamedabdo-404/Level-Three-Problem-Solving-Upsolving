#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<ll>>adj(100005);
vector<int>vis(100005);
bool hasCycle=false;
vector<int>ans;
void dfs2(int node){//O(n+m)
  vis[node]=2;
  for(auto i:adj[node]){
    if(!vis[i])
     { 
      dfs2(i);
     }
     else if(vis[i]==2){
      hasCycle=true;
     }
  }
  vis[node]=1;
  ans.push_back(node);
}
void solve(){
  ll n,m;
  cin>>n>>m;
  
  for (int i = 0; i < m; i++)//Directed
  {
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
  }
  for (int i = 1; i <= n; i++)//O(n+m)
  {
    if(!vis[i]){
      dfs2(i);
    }
  }
  if(hasCycle){
    cout<<-1;
  }else{
  reverse(ans.begin(),ans.end());//O(n)
  for(auto i:ans){
    cout<<i<<' ';
  }}
  cout<<endl;
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