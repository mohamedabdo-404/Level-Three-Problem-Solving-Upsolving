#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

ll n,m,k;

vector<vector<pair<int,pair<ll,ll>>>>adj(100005);
vector<ll>dist(100005,LLONG_MAX);
vector<ll>wisdom;

bool dijkstra(ll maxWisdom){//O((n+m)*log(n))

  //dist , node
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

  fill(dist.begin(),dist.end(),LLONG_MAX);

  dist[1]=0;
  pq.push({0,1});

  while (!pq.empty())
  {
     auto [cur_dist,cur_node] =pq.top();
     pq.pop();

     if(cur_dist!=dist[cur_node]){
      continue;
     }

     for(auto i:adj[cur_node]){//node , cost , wisdom

      if(i.second.second>maxWisdom){
        continue;
      }

      if(dist[cur_node]+i.second.first<dist[i.first]){
        dist[i.first]=dist[cur_node]+i.second.first;
        pq.push({dist[i.first],i.first});
      }
     }
  }

  return dist[n]<k;
}

void solve(){

  cin>>n>>m>>k;
  
  adj.assign(n+1,{});
  wisdom.clear();


  for (int i = 0; i < m; i++)//UnDirected
  {
    int x,y;
    ll c,w;

    cin>>x>>y>>c>>w;

    adj[x].push_back({y,{c,w}});
    adj[y].push_back({x,{c,w}});

    wisdom.push_back(w);
  }

  sort(wisdom.begin(),wisdom.end());
  wisdom.erase(unique(wisdom.begin(),wisdom.end()),wisdom.end());

  //Binary Search

  int l=0,r=wisdom.size()-1;
  ll ans=-1;

  while(l<=r){

    int mid=(l+r)/2;

    if(dijkstra(wisdom[mid])){
      ans=wisdom[mid];
      r=mid-1;
    }
    else{
      l=mid+1;
    }
  }

  cout<<ans<<endl;
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