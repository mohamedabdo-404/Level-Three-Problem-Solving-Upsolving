
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll MOD = 1e9 + 7;
int N;
int a[21][21];
ll dp[1 << 21];
bool vis[1 << 21];

ll rec(int mask) {
    if (mask == (1 << N) - 1)
        return 1;

    if (vis[mask])
        return dp[mask];

    vis[mask] = true;
    ll &ret = dp[mask];
    ret = 0;

    int man = __builtin_popcount((unsigned int)mask);

    for (int j = 0; j < N; j++) {
        if (mask & (1 << j))
            continue;

        if (a[man][j] == 1)
            ret = (ret + rec(mask | (1 << j))) % MOD;
    }

    return ret;
}

void Sol() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    cout << rec(0) << endl;
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
