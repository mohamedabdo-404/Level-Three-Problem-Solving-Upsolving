#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<int>> adj(200005);
vector<int> vis(200005);
vector<int> level(200005);

vector<int> init(200005);
vector<int> goal(200005);
vector<int> ans;

void bfsCheck(int start){//O(n+m)
    queue<pair<int,pair<int,int>>>q;

    q.push({start,{0,0}});
    vis[start]=1;
    level[start]=0;

    while(!q.empty()){
        int cur=q.front().first;
        int flip[2];

        flip[0]=q.front().second.first;
        flip[1]=q.front().second.second;

        q.pop();

        int depth=level[cur]%2;

        if((init[cur]^flip[depth])!=goal[cur]){
            ans.push_back(cur);
            flip[depth]^=1;
        }

        for(auto i:adj[cur]){
            if(!vis[i]){
                vis[i]=1;
                level[i]=level[cur]+1;

                q.push({i,{flip[0],flip[1]}});
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;

    for(int i=1;i<=n;i++){
        adj[i].clear();
        vis[i]=0;
        level[i]=0;
    }

    ans.clear();

    // Build graph
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Take initial values
    for(int i=1;i<=n;i++){
        cin>>init[i];
    }

    // Take goal values
    for(int i=1;i<=n;i++){
        cin>>goal[i];
    }

    // Check and find minimum operations
    bfsCheck(1);

    cout<<ans.size()<<endl;

    for(auto i:ans){
        cout<<i<<endl;
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