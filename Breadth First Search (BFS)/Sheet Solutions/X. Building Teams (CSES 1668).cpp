#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'


vector<vector<ll>>adj(100005);
vector<int>color(100005,-1);

bool bfsCheck(int start){//O(n+m)
    queue<int>q;
    q.push(start);
    color[start]=1;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(auto i:adj[cur]){
            if(color[i]==-1){
                color[i]=3-color[cur]; // 1<->2
                q.push(i);
            }else if(color[i]==color[cur]){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    ll n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok=true;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bfsCheck(i)){ok=false;break;}
        }
    }

    if(!ok){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(int i=1;i<=n;i++) cout<<color[i]<<' ';
        cout<<endl;
    }
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
