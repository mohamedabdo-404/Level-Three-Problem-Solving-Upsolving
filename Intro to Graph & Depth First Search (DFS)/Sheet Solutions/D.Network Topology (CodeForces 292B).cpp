#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>> adj(100005);
vector<int>vis(100005);

void solve(){

    ll n,m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){//Undirected
        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll one = 0;
    ll two = 0;
    ll nMinusOne = 0;

    for(int i = 1; i <= n; i++){//O(n)

        if(adj[i].size() == 1)
            one++;

        if(adj[i].size() == 2)
            two++;

        if(adj[i].size() == n-1)
            nMinusOne++;
    }

    if(one == 2 && two == n-2){
        cout<<"bus topology";
    }
    else if(two == n){
        cout<<"ring topology";
    }
    else if(one == n-1 && nMinusOne == 1){
        cout<<"star topology";
    }
    else{
        cout<<"unknown topology";
    }

    cout<<endl;
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