#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<pair<ll,ll>>>adj(100005);
vector<vector<ll>>dist(100005,vector<ll>(2,LLONG_MAX));
// state = 0 => not use
// state = 1 => use
void dijkstra(int start){//O((n+m)*log(n))
  //dist , node
  priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>>pq;
  dist[start][0]=0;
  pq.push({0,start,0});
 
  while (!pq.empty())
  {
     auto [cur_dist,cur_node,cur_state] =pq.top();
    pq.pop();
     if(cur_dist!=dist[cur_node][cur_state]){
      continue;
     }
     for(auto i:adj[cur_node]){//node , dist
      //Don't use
      if(dist[cur_node][cur_state]+i.second<dist[i.first][cur_state]){
      dist[i.first][cur_state]=dist[cur_node][cur_state]+i.second;
      pq.push({dist[i.first][cur_state],i.first,cur_state});}
 
      //use
      if(cur_state==0){
        if(dist[cur_node][0]+(i.second/2)<dist[i.first][1]){
      dist[i.first][1]=dist[cur_node][0]+(i.second/2);
      pq.push({dist[i.first][1],i.first,1});}
      }
     }
  }
  
}
void solve(){
  ll n,m;
  cin>>n>>m;
  for (int i = 0; i < m; i++)//UnDirected
  {
    ll x,y,t;
    cin>>x>>y>>t;
    adj[x].push_back({y,t});
  }
  dijkstra(1);//O((n+m)*log(n))
  cout<<dist[n][1]<<endl;
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