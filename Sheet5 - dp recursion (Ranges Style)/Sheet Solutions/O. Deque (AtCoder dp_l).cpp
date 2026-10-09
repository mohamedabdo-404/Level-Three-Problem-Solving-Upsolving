
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n;
ll a[3005];
ll dp[3005][3005];
bool vis[3005][3005];

ll rec(int l, int r){
    if(l > r) return 0;
    if(l == r) return a[l];

    if(vis[l][r]) return dp[l][r];
    vis[l][r] = true;

    ll &ret = dp[l][r];

    // take left: gain a[l], opponent gets rec(l+1,r) advantage
    // take right: gain a[r], opponent gets rec(l,r-1) advantage
    return ret = max(a[l] - rec(l + 1, r),
                     a[r] - rec(l, r - 1));
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

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
