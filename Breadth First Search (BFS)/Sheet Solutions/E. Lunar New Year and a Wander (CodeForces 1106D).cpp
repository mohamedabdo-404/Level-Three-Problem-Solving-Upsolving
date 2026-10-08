#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'


vector<vector<ll>>adj(100005);
vector<int>vis(100005);

void solve(){
    ll n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Modified BFS with min-heap
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(1);
    vis[1]=1;

    vector<int>ans;

    while(!pq.empty()){
        int cur=pq.top();
        pq.pop();
        ans.push_back(cur);

        for(auto i:adj[cur]){
            if(!vis[i]){
                vis[i]=1;
                pq.push(i);
            }
        }
    }

    for(auto x:ans) cout<<x<<' ';
    cout<<endl;
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
