#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<int>>adj(100005);
vector<int>indegree(100005);
vector<int>par(100005);

void bfs(int start){//O(n+m)

    queue<int>q;
    q.push(start);

    while(!q.empty()){

        int cur=q.front();
        q.pop();

        for(auto i:adj[cur]){

            indegree[i]--;

            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
}

void solve(){

    ll n,k;
    cin>>n>>k;

    for(int i=1;i<=k;i++){

        int w;
        cin>>w;

        for(int j=0;j<w;j++){

            int x;
            cin>>x;

            // x must be below i
            adj[i].push_back(x);
            indegree[x]++;
        }
    }

    queue<int>q;

    for(int i=1;i<=n;i++){

        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>order;

    while(!q.empty()){

        int cur=q.front();
        q.pop();

        order.push_back(cur);

        for(auto i:adj[cur]){

            indegree[i]--;

            if(indegree[i]==0){
                q.push(i);
            }
        }
    }

    // First node becomes the main boss
    par[order[0]]=0;

    for(int i=1;i<n;i++){

        int cur=order[i];

        // Connect every node to the previous node
        par[cur]=order[i-1];
    }

    for(int i=1;i<=n;i++){
        cout<<par[i]<<" ";
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