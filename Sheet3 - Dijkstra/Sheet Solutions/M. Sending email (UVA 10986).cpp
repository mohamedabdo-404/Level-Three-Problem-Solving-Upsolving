#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<pair<ll,ll>>>adj(20005);
vector<ll>dist(20005,LLONG_MAX);

void dijkstra(int start){//O((n+m)log n)
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        auto[cur_dist,cur_node]=pq.top();pq.pop();
        if(cur_dist!=dist[cur_node]) continue;

        for(auto[nb,w]:adj[cur_node]){
            if(dist[cur_node]+w<dist[nb]){
                dist[nb]=dist[cur_node]+w;
                pq.push({dist[nb],nb});
            }
        }
    }
}

void solve(int caseNum){
    ll n,m,S,T;
    cin>>n>>m>>S>>T;

    for(int i=0;i<n;i++){adj[i].clear();dist[i]=LLONG_MAX;}

    for(int i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(S);

    cout<<"Case #"<<caseNum<<": ";
    if(dist[T]==LLONG_MAX) cout<<"unreachable"<<endl;
    else cout<<dist[T]<<endl;
}

int main(){
    Fast

    int T=1;
    cin>>T;

    for(int i=1;i<=T;i++){
        solve(i);
    }
}
