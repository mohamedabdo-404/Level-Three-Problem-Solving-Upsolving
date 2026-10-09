
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n;
int a[105];
int dp[105][105][105];

int rec(int i, int j, int k){
    if(i == n) return (j == 0 ? 0 : 1e9);
    if(j >= n) return 1e9;

    int &ret = dp[i][j][k];
    if(ret != -1) return ret;

    ret = 1e9;

    // Option 1: Don't use the charge
    int nj = (j > 0 ? j + 1 : (k == 0 ? 1 : 0));
    int nk = max(0, k - 1);

    ret = min(ret, rec(i + 1, nj, nk));

    // Option 2: Use the charge to the left
    nj = (j > 0 ? j + 1 : 0);
    if(nj <= a[i]) nj = 0;

    ret = min(ret, 1 + rec(i + 1, nj, nk));

    // Option 3: Use the charge to the right
    nj = (j > 0 ? j + 1 : 0);
    nk = max(a[i] - 1, k - 1);

    ret = min(ret, 1 + rec(i + 1, nj, nk));

    return ret;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
}

int main(){
    Fast
    ll T = 1;
    cin >> T;
    while(T--) solve();
}
