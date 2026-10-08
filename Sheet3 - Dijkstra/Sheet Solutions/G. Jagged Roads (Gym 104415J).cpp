#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int N = 1e5+5;

vector<vector<pair<int,double>>> adj(N);
vector<double> dist(N,-1.0);

void dijkstra(int start){//O((n+m)*log(n))

  //dist , node
  priority_queue<pair<double,int>,
                 vector<pair<double,int>>,
                 greater<pair<double,int>>>pq;

  pq.push({0.0,start});

  while(!pq.empty())
  {
    auto [cur_dist,cur_node]=pq.top();
    pq.pop();

    if(dist[cur_node]!=-1.0){
      continue;
    }

    dist[cur_node]=cur_dist;

    for(auto i:adj[cur_node]){//node , dist

      if(dist[i.first]==-1.0){
        pq.push({cur_dist+i.second,i.first});
      }
    }
  }
}

//Log
double lg(int c){
  return log(c)/log(7);
}

void solve(){

  ll n,m;
  cin>>n>>m;

  for(int i=0;i<m;i++){

    int u,v,c;
    cin>>u>>v>>c;

    double cost=lg(c);

    adj[u].push_back({v,cost});
    adj[v].push_back({u,cost});
  }

  dijkstra(1);

  cout<<fixed<<setprecision(15)<<dist[n]<<endl;
}

int main(){

  Fast

  ll T=1;
  // cin>>T;
  // cin.ignore();

  while(T--){
    solve();
  }
}