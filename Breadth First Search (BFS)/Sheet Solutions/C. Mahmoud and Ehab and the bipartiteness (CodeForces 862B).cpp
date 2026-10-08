#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(100005);
vector<int>color(100005,-1);

void bfs(int start){//O(n+m)
    queue<int>q;
    q.push(start);
    color[start]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(auto i:adj[cur]){
            if(color[i]==-1){
                color[i]=1-color[cur];
                q.push(i);
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    ll cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++){
        if(color[i]==0) cnt0++;
        else cnt1++;
    }

    cout<<cnt0*cnt1-(n-1)<<endl;
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
