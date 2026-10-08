#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<pair<int,int>>>adj(200005); // adj[u] = {v, edge_index}
vector<int>color(200005,-1);
int ans[200005]; // ans[i] = 0 means edge i goes u->v, 1 means v->u

bool bfsCheck(int start){//O(n+m)
    queue<int>q;
    q.push(start);
    color[start]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(auto[nb,idx]:adj[cur]){
            if(color[nb]==-1){
                color[nb]=1-color[cur];
                q.push(nb);
            }else if(color[nb]==color[cur]){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<pair<int,int>>edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[i]={u,v};
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }

    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bfsCheck(i)){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;

    for(int i=0;i<m;i++){
        int u=edges[i].first,v=edges[i].second;
        // color[u]==0 => u is in set0, color[v]==1 => edge u->v (ans=0)
        // color[u]==1 => u is in set1, color[v]==0 => edge v->u (ans=1)
        if(color[u]==0) cout<<0;
        else cout<<1;
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
