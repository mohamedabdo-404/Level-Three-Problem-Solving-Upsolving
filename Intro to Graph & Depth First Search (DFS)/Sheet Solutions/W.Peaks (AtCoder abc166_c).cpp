#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(100005);
vector<ll>h(100005);

void solve(){

    ll n,m;
    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        cin>>h[i];
    }

    for(int i = 0; i < m; i++){//Undirected

        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++){

        bool good = true;

        for(auto j:adj[i]){

            if(h[i] <= h[j]){
                good = false;
                break;
            }
        }

        if(good){
            ans++;
        }
    }

    cout<<ans<<endl;
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