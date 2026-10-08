#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<pair<ll,ll>>>adj(100005);
vector<int>dist(100005,INT_MAX);
void dijkstra(int start){
  //dist , node
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
  dist[start]=0;
  pq.push({0,start});

  while (!pq.empty())
  {
     auto [cur_dist,cur_node] =pq.top();
     if(cur_dist!=dist[cur_node]){
      pq.pop();
      continue;
     }
     for(auto i:adj[cur_node]){//node , dist
      if(dist[cur_node]+i.second<dist[i.first]){
      dist[i.first]=dist[cur_node]+i.second;
      pq.push({dist[i.first],i.first});}
     }
     pq.pop();
  }
  
}
void solve(){
  fill(dist.begin(),dist.end(),INT_MAX);
  ll n,m,st,en;
  cin>>n>>m>>st>>en;
  for(int i = 0; i < n; i++){
    adj[i].clear();
  }
  for (int i = 0; i < m; i++)//UnDirected
  {
    ll x,y,t;
    cin>>x>>y>>t;
    adj[x].push_back({y,t});
    adj[y].push_back({x,t});
  }
  dijkstra(st);
  if(dist[en]==INT_MAX){
    cout<<"NONE\n";
  }else{
    cout<<dist[en]<<endl;
  }
  
}
int main(){
    Fast
    ll T = 1;
    cin >> T;
    // cin.ignore();
    while (T--){
        solve();
    }
}