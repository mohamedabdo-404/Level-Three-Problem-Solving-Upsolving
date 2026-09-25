#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<ll>deg(200005);

void solve(){

    ll n,m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){

        ll x,y;
        cin>>x>>y;

        deg[x]++;
        deg[y]++;
    }

    for(int i = 1; i <= n; i++){
        cout<<deg[i]<<' ';
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