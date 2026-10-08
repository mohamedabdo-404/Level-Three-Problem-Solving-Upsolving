#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<int>> adj(1000005);
vector<int> indegree(1000005);


void bfs(int n){//O(n+m)

    queue<int>q;

    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int cnt=0;

    while(!q.empty()){

        int cur=q.front();
        q.pop();

        cout<<cur<<endl;
        cnt++;

        for(auto i:adj[cur]){

            indegree[i]--;

            if(indegree[i]==0){
                q.push(i);
            }
        }
    }

    if(cnt!=n){
        cout<<"IMPOSSIBLE"<<endl;
    }
}

void solve(ll n,ll m){


    for(int i=1;i<=n;i++){
        adj[i].clear();
        indegree[i]=0;
    }


    for(int i=0;i<m;i++){

        int a,b;
        cin>>a>>b;

        // a is on top of b
        adj[a].push_back(b);
        indegree[b]++;
    }

    bfs(n);
}

int main(){

    Fast

    while(true){

        ll n,m;
        cin>>n>>m;

        if(n==0 && m==0){
            break;
        }

        solve(n,m);
    }
}