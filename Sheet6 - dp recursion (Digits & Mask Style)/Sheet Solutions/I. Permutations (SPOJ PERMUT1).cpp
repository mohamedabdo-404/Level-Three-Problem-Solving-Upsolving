
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int MAXN = 15, MAXK = 100;
ll dp[MAXN][MAXK * MAXN];
bool vis[MAXN][MAXK * MAXN];

ll rec(int n, int k) {
    if (k < 0) return 0;
    if (n == 0) return k == 0 ? 1 : 0;

    if (vis[n][k]) return dp[n][k];

    vis[n][k] = true;
    ll &ret = dp[n][k];
    ret = 0;

    for (int i = 0; i <= min(k, n - 1); i++)
        ret += rec(n - 1, k - i);

    return ret;
}

void Sol() {
    int d;
    cin >> d;

    while (d--) {
        int n, k;
        cin >> n >> k;

        memset(vis, false, sizeof(vis));

        cout << rec(n, k) << endl;
    }
}

int main() {
    Fast
    ll T = 1;
    // cin>>T;
    // cin.ignore();
    while (T--) {
        Sol();
    }
    return 0;
}
