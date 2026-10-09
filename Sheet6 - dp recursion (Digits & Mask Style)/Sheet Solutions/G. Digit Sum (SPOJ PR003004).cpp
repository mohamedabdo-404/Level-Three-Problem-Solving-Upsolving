
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

string s;
ll dp[20][2];
ll cnt[20][2];
bool vis[20][2];

pair<ll, ll> rec(int pos, int tight) {
    if (pos == s.size())
        return {1, 0};

    if (vis[pos][tight])
        return {cnt[pos][tight], dp[pos][tight]};

    ll ways = 0, sum = 0;
    int limit = tight ? s[pos] - '0' : 9;

    for (int d = 0; d <= limit; d++) {
        int ntight = tight && (d == s[pos] - '0');

        pair<ll, ll> res = rec(pos + 1, ntight);

        ways += res.first;
        sum += res.second + d * res.first;
    }

    vis[pos][tight] = true;
    cnt[pos][tight] = ways;
    dp[pos][tight] = sum;

    return {ways, sum};
}

ll getSum(ll n) {
    if (n < 0)
        return 0;

    s = to_string(n);
    memset(vis, false, sizeof(vis));

    return rec(0, 1).second;
}

void Sol() {
    ll a, b;
    cin >> a >> b;

    cout << getSum(b) - getSum(a - 1) << endl;
}

int main() {
    Fast
    ll T = 1;
    cin >> T;
    // cin.ignore();

    while (T--)
        Sol();

    return 0;
}
