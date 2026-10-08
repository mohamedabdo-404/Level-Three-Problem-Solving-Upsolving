#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

ll n,m;
char a[55][55];
bool vis[55][55];

ll ans;

bool danger(int i,int j){

    // Up
    if(a[i-1][j] == 'T')
        return true;

    // Down
    if(a[i+1][j] == 'T')
        return true;

    // Right
    if(a[i][j+1] == 'T')
        return true;

    // Left
    if(a[i][j-1] == 'T')
        return true;

    return false;
}

void dfs(int i,int j){//O(n*m)

    vis[i][j] = true;

    if(a[i][j] == 'G'){
        ans++;
    }

    if(danger(i,j)){
        return;
    }

    // Up
    if(!vis[i-1][j] && a[i-1][j] != '#' && a[i-1][j] != 'T')
        dfs(i-1,j);

    // Down
    if(!vis[i+1][j] && a[i+1][j] != '#' && a[i+1][j] != 'T')
        dfs(i+1,j);

    // Right
    if(!vis[i][j+1] && a[i][j+1] != '#' && a[i][j+1] != 'T')
        dfs(i,j+1);

    // Left
    if(!vis[i][j-1] && a[i][j-1] != '#' && a[i][j-1] != 'T')
        dfs(i,j-1);
}

void solve(){

    ans = 0;
    memset(vis,0,sizeof(vis));

    ll x,y;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            cin>>a[i][j];

            if(a[i][j] == 'P'){
                x = i;
                y = j;
            }
        }
    }

    dfs(x,y);

    cout<<ans<<endl;
}

int main(){

    Fast

    while(cin>>m>>n){
        solve();
    }
}