#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<int>>adj(10005);
vector<int>indegree(10005,0);

void solve(){
    ll n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    // Kahn's with min-heap for lex smallest
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) pq.push(i);
    }

    vector<int>order;
    while(!pq.empty()){
        int cur=pq.top();pq.pop();
        order.push_back(cur);
        for(auto i:adj[cur]){
            indegree[i]--;
            if(indegree[i]==0) pq.push(i);
        }
    }

    if((int)order.size()<n){
        cout<<"Sandro fails."<<endl;
    }else{
        for(int i=0;i<(int)order.size();i++){
            cout<<order[i];
            if(i+1<(int)order.size()) cout<<' ';
        }
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
