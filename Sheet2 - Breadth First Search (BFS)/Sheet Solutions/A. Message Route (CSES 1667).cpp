#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<ll>>adj(100005);
vector<int>vis(100005),level(100005),p(100005), travel;
void bfs(int start){
  queue<int>q;
  q.push(start);
  vis[start]=1;
  level[start]=0;
  p[start]=0;
 
  while (!q.empty())
  {
     int cur=q.front();
     travel.push_back(cur);
    for(auto i:adj[cur]){
      if(!vis[i]){
        q.push(i);
        vis[i]=1;
        level[i]=level[cur]+1;
        p[i]=cur;
      }
    }
    q.pop();
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
  bfs(1);//O(n+m)
  if(!vis[n]){
    cout<<"IMPOSSIBLE"<<endl;
  }else{
    cout<<level[n]+1<<endl;
  vector<int>ans;
  ll cur=n;
  while (cur)//O(n)
  {
    ans.push_back(cur);
    cur=p[cur];
  }
  reverse(ans.begin(),ans.end());//O(n)
  for(auto i:ans){//O(n)
    cout<<i<<' ';
  }
  cout<<endl;
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