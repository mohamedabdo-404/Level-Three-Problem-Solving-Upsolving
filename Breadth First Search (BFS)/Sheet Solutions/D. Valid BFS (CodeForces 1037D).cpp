#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<ll>>adj(200005);

void solve(){
    ll n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>seq(n);
    vector<int>pos(n+1);
    for(int i=0;i<n;i++){
        cin>>seq[i];
        pos[seq[i]]=i;
    }

    if(seq[0]!=1){
        cout<<"No"<<endl;
        return;
    }

    // Sort adjacency lists by position in the given sequence
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end(),[&](int a,int b){
            return pos[a]<pos[b];
        });
    }

    // BFS from node 1 and compare
    vector<int>vis(n+1,0);
    queue<int>q;
    q.push(1);
    vis[1]=1;

    vector<int>bfsOrder;

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        bfsOrder.push_back(cur);

        for(auto i:adj[cur]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(bfsOrder[i]!=seq[i]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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
