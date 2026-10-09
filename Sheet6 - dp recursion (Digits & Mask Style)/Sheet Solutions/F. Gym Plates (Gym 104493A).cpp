
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int N = 59049;

ll n;
vector<ll> v;
ll dp[105][N];
int pw[11];
int cnt[N][10];
int freq[105][10];
int nxt[105][N];

ll rec(ll idx, int mask) {
    if (idx == n)
        return 0;

    ll &ret = dp[idx][mask];
    if (ret != -1)
        return ret;

    ret = rec(idx + 1, mask);

    int newMask = nxt[idx][mask];

    if (newMask != -1)
        ret = max(ret, v[idx] + rec(idx + 1, newMask));

    return ret;
}

void Sol() {
    cin >> n;

    v.resize(n);

    for (ll &x : v)
        cin >> x;

    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < n; i++) {
        string s = to_string(v[i]);

        for (char c : s)
            freq[i][c - '0']++;
    }

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < N; mask++) {
            bool ok = true;
            int newMask = mask;

            for (int d = 0; d < 10; d++) {
                int cur = cnt[mask][d] + freq[i][d];

                if (cur > 2) {
                    ok = false;
                    break;
                }

                newMask += freq[i][d] * pw[d];
            }

            nxt[i][mask] = (ok ? newMask : -1);
        }
    }

    cout << rec(0, 0) << endl;
}

int main() {
    Fast

    pw[0] = 1;
    for (int i = 1; i <= 10; i++)
        pw[i] = pw[i - 1] * 3;

    for (int mask = 0; mask < N; mask++) {
        for (int d = 0; d < 10; d++)
            cnt[mask][d] = (mask / pw[d]) % 3;
    }

    ll T = 1;
    cin >> T;
    // cin.ignore();

    while (T--)
        Sol();

    return 0;
}
