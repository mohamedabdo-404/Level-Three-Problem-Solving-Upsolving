#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<int>>adj(2005);
vector<int>color(2005,-1);

bool bfsCheck(int start){//O(n+m)
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
            if(!bfsCheck(i)) ok=false;
        }
    }

    if(ok) cout<<"No suspicious bugs found!"<<endl;
    else cout<<"Suspicious bugs found!"<<endl;
}

int main(){
    Fast

    ll T=1;
    cin>>T;
    // cin.ignore();

    int tc=1;
    while(T--){
        for(int i=0;i<2005;i++){adj[i].clear();color[i]=-1;}
        cout<<"Scenario #"<<tc++<<":"<<endl;
        solve();
    }
}
