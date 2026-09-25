#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(55);
vector<int>vis(55);

vector<ll>one;
vector<vector<ll>>two;
vector<vector<ll>>three;

void dfs(int node,vector<ll>&v){//O(n+m)

    vis[node] = 1;
    v.push_back(node);

    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i,v);
        }
    }
}

void solve(){

    ll n,m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){//Undirected
        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){

        if(!vis[i]){

            vector<ll>v;
            dfs(i,v);

            if(v.size() == 1)
                one.push_back(v[0]);

            else if(v.size() == 2)
                two.push_back(v);

            else if(v.size() == 3)
                three.push_back(v);

            else{
                cout<<-1<<endl;
                return;
            }
        }
    }

    if(two.size() > one.size()){
        cout<<-1<<endl;
        return;
    }

    for(auto v:two){

        cout<<v[0]<<' '<<v[1]<<' '<<one.back()<<endl;
        one.pop_back();
    }

    if(one.size() % 3 != 0){
        cout<<-1<<endl;
        return;
    }

    for(auto v:three){

        cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<endl;
    }

    for(int i = 0; i < one.size(); i += 3){

        cout<<one[i]<<' '<<one[i+1]<<' '<<one[i+2]<<endl;
    }
}

int main(){

    Fast

    ll T = 1;
    // cin >> T;
    // cin.ignore();

    while(T--){
        solve();
    }
}