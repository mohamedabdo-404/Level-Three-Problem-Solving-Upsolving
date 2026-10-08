#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<pair<ll,ll>>>adj(100005);
vector<ll>dist(100005,LLONG_MAX);
void dijkstra(int start){//O((n+m)*log(n))
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
  ll n,m;
  cin>>n>>m;
  for (int i = 0; i < m; i++)//UnDirected
  {
    ll x,y,t;
    cin>>x>>y>>t;
    adj[x].push_back({y,t});
    adj[y].push_back({x,t});
  }
  dijkstra(1);
  if(dist[n]==LLONG_MAX){
    cout<<-1<<endl;
  }else{
    vector<int>ans;
    ll cur=n;
    while (cur!=1)
    {
      ans.push_back(cur);
      for(auto i:adj[cur]){
        if(dist[i.first]+i.second==dist[cur]){
          cur=i.first;
        }
      }
    }
    ans.push_back(1);

    reverse(ans.begin(),ans.end());
    for(auto i:ans){
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