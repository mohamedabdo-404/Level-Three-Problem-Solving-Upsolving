#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<int>>adj(300005);
vector<int>dist(300005,INT_MAX);
bool isBlack[300005];

void solve(){

    ll n,start;
    cin>>n>>start;

    vector<int>colorOrder(n);

    for(int i=1;i<n;i++){
        cin>>colorOrder[i];
    }

    // Reset
    for(int i=1;i<=n;i++){
        adj[i].clear();
        dist[i]=INT_MAX;
        isBlack[i]=false;
    }

    // Take Graph
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    isBlack[start]=true;
    dist[start]=0;

    queue<int>bfsQ;
    bfsQ.push(start);

    // Initial BFS
    while(!bfsQ.empty()){

        int cur=bfsQ.front();
        bfsQ.pop();

        for(auto nb:adj[cur]){

            if(dist[nb]>dist[cur]+1){

                dist[nb]=dist[cur]+1;
                bfsQ.push(nb);
            }
        }
    }

    int ans=INT_MAX;

    for(int i=1;i<n;i++){

        int c=colorOrder[i];

        // Distance from c to nearest black vertex
        ans=min(ans,dist[c]);

        // Make c black
        isBlack[c]=true;
        dist[c]=0;

        bfsQ.push(c);

        // Update distances
        while(!bfsQ.empty()){

            int cur=bfsQ.front();
            bfsQ.pop();

            for(auto nb:adj[cur]){

                if(dist[nb]>dist[cur]+1){

                    dist[nb]=dist[cur]+1;
                    bfsQ.push(nb);
                }
            }
        }

        cout<<ans<<" ";
    }

    cout<<endl;
}

int main(){

    Fast

    ll T=1;
    cin>>T;
    // cin.ignore();

    while(T--){
        solve();
    }
}