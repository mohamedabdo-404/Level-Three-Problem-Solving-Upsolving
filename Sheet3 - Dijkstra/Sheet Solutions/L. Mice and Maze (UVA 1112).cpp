#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<pair<ll,ll>>>radj(105); // reversed adjacency
vector<ll>dist(105,LLONG_MAX);

void dijkstra(int start){//O((n+m)log n)
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        auto[cur_dist,cur_node]=pq.top();pq.pop();
        if(cur_dist!=dist[cur_node]) continue;

        for(auto[nb,w]:radj[cur_node]){
            if(dist[cur_node]+w<dist[nb]){
                dist[nb]=dist[cur_node]+w;
                pq.push({dist[nb],nb});
            }
        }
    }
}

void solve(){
    ll n,E,T,m;
    cin>>n>>E>>T>>m;

    for(int i=1;i<=n;i++){radj[i].clear();dist[i]=LLONG_MAX;}

    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        // Reverse edge: v->u in reversed graph
        radj[v].push_back({u,w});
    }

    dijkstra(E);

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(dist[i]<=T) cnt++;
    }

    cout<<cnt<<endl;
}

int main(){
    Fast

    ll T=1;
    cin>>T;
    // cin.ignore();

    bool first=true;
    while(T--){
        if(!first) cout<<endl;
        first=false;
        solve();
    }
}
