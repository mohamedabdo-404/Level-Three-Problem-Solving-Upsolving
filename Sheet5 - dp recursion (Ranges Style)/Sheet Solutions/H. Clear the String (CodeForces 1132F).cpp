
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

string s;
int n;
ll dp[505][505];
bool vis[505][505];

ll rec(int l, int r){
    if(l > r) return 0;
    if(l == r) return 1;

    if(vis[l][r]) return dp[l][r];
    vis[l][r] = true;

    ll &ret = dp[l][r];

    ret = 1 + rec(l + 1, r);

    for(int k = l + 1; k <= r; k++){
        if(s[k] == s[l]){
            ret = min(ret, rec(l + 1, k - 1) + rec(k, r));
        }
    }

    return ret;
}

void solve(){
    cin >> n >> s;

    memset(vis, false, sizeof(vis));

    cout << rec(0, n - 1) << endl;
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
