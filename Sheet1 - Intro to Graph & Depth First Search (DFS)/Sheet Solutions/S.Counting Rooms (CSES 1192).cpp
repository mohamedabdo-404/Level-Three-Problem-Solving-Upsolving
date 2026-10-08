#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

ll n,m;
char a[1005][1005];
bool vis[1005][1005];

void dfs(int i,int j){//O(n*m)

    vis[i][j] = 1;

    // Up
    if(i-1 >= 0 && !vis[i-1][j] && a[i-1][j] == '.')
        dfs(i-1,j);

    // Down
    if(i+1 < n && !vis[i+1][j] && a[i+1][j] == '.')
        dfs(i+1,j);

    // Right
    if(j+1 < m && !vis[i][j+1] && a[i][j+1] == '.')
        dfs(i,j+1);

    // Left
    if(j-1 >= 0 && !vis[i][j-1] && a[i][j-1] == '.')
        dfs(i,j-1);
}

void solve(){

    cin>>n>>m;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(a[i][j] == '.' && !vis[i][j]){

                ans++;

                dfs(i,j);
            }
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