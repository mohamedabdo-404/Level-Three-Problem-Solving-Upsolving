#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<int>vis(100005);

void solve(){

    ll n,m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        ll x,y;
        cin>>x>>y;

        vis[x] = 1;
        vis[y] = 1;
    }

    ll center = 0;

    for(int i = 1; i <= n; i++){//O(n)
        if(!vis[i]){
            center = i;
            break;
        }
    }

    cout<<n-1<<endl;

    for(int i = 1; i <= n; i++){
        if(i != center){
            cout<<center<<' '<<i<<endl;
        }
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