#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

//Graph
struct Rectangle{
    ll h,w,d;
    int k;
};

vector<Rectangle> a;
vector<vector<pair<int,double>>> adj;
vector<double> dist;

void dijkstra(int start){//O((n+m)*log(n))

  //dist , node
  priority_queue<pair<double,int>,
                 vector<pair<double,int>>,
                 greater<pair<double,int>>>pq;

  dist[start]=0;
  pq.push({0,start});

  while (!pq.empty())
  {
    auto [cur_dist,cur_node]=pq.top();
    pq.pop();

    if(cur_dist!=dist[cur_node]){
      continue;
    }

    for(auto i:adj[cur_node]){//node , dist

      if(dist[cur_node]+i.second<dist[i.first]){
        dist[i.first]=dist[cur_node]+i.second;
        pq.push({dist[i.first],i.first});
      }
    }
  }
}

void solve(){

  ll n,L,U;
  cin>>n>>L>>U;

  a.clear();

  for(int i=0;i<n;i++){

    ll h,w,d;
    int k;

    cin>>h>>w>>d>>k;

    a.push_back({h,w,d,k});
  }

  //Build Graph
  // Start = 0
  // Rectangles = 1 ... n
  // End = n+1

  adj.assign(n+2,{});
  dist.assign(n+2,1e100);

  //Start / End
  for(int i=1;i<=n;i++){

    // Start -> Rectangle
    adj[0].push_back({i,(double)a[i-1].d});

    // Rectangle -> End
    adj[i].push_back({
      n+1,
      (double)(L-(a[i-1].d+a[i-1].h))
    });
  }

  // Start -> End
  adj[0].push_back({n+1,(double)L});

  //Rectangle -> Rectangle
  for(int i=1;i<=n;i++){

    for(int j=i+1;j<=n;j++){

      Rectangle A=a[i-1];
      Rectangle B=a[j-1];

      // Position in the street

      ll A1=A.d;
      ll A2=A.d+A.h;

      ll B1=B.d;
      ll B2=B.d+B.h;

      // Distance in the length direction

      ll dx=0;

      if(A2<B1){
        dx=B1-A2;
      }
      else if(B2<A1){
        dx=A1-B2;
      }

      // Distance in the width direction

      ll dy=0;

      if(A.k!=B.k){
        dy=U-A.w-B.w;

        if(dy<0){
          dy=0;
        }
      }

      double w=sqrt(
        (double)dx*dx+
        (double)dy*dy
      );

      adj[i].push_back({j,w});
      adj[j].push_back({i,w});
    }
  }

  dijkstra(0);

  cout<<fixed<<setprecision(6)<<dist[n+1]<<endl;
}

int main(){

  Fast
    freopen("street.in", "r", stdin);//input: street.in

  ll T=1;
  cin>>T;

  while(T--){
    solve();
  }
}