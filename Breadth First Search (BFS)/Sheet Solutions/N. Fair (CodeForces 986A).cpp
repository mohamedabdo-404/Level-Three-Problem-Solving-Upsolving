#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    ll n,m,k,s;
    cin>>n>>m>>k>>s;

    vector<int>type(n+1);
    for(int i=1;i<=n;i++) cin>>type[i];

    vector<vector<ll>>adj(n+1);
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dist[t][v] = min dist from node v to nearest node of type t
    // But k can be up to n => store as dist[v][k] = vector
    // For each type, run multi-source BFS
    vector<vector<ll>>dist(k+1,vector<ll>(n+1,-1));

    for(int t=1;t<=k;t++){
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(type[i]==t){
                dist[t][i]=0;
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(auto nb:adj[cur]){
                if(dist[t][nb]==-1){
                    dist[t][nb]=dist[t][cur]+1;
                    q.push(nb);
                }
            }
        }
    }

    for(int v=1;v<=n;v++){
        vector<ll>dists;
        for(int t=1;t<=k;t++){
            if(dist[t][v]!=-1) dists.push_back(dist[t][v]);
        }
        sort(dists.begin(),dists.end());
        ll sum=0;
        for(int i=0;i<s&&i<(int)dists.size();i++) sum+=dists[i];
        cout<<sum<<' ';
    }
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
