#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){

    ll n;
    cin>>n;

    vector<ll>p(n+1);
    vector<vector<ll>>adj(n+1);
    vector<int>vis(n+1);
    vector<vector<ll>>ans;

    ll root;

    for(int i = 1; i <= n; i++){
        cin>>p[i];

        if(p[i] == i){
            root = i;
        }
        else{
            adj[p[i]].push_back(i);
        }
    }

    // Find all leaves
    for(int i = 1; i <= n; i++){

        if(adj[i].empty()){

            vector<ll>path;
            ll node = i;

            while(!vis[node]){

                vis[node] = 1;
                path.push_back(node);

                if(p[node] == node)
                    break;

                node = p[node];
            }

            reverse(path.begin(),path.end());

            ans.push_back(path);
        }
    }

    cout<<ans.size()<<endl;

    for(auto path:ans){

        cout<<path.size()<<endl;

        for(auto i:path){
            cout<<i<<' ';
        }

        cout<<endl;
    }
}

int main(){

    Fast

    ll T = 1;
    cin>>T;
    // cin.ignore();

    while(T--){
        solve();
    }
}