#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
ll n;
vector<ll> v;
ll dp[401][301][2];
string s;
vector<string> res;
ll rec(ll i, ll j, ll f) {
    if (i == 401)
        return f && !j;
    ll dig = s[i] - 48;
    if (dp[i][j][f] == -1) {
        dp[i][j][f] = 0;
        for (int k = 0; k < 10; ++k) {
            if ((k < dig && !f) || k > j)//valid in digit > k and smallest yet   ||  cost > sum
                continue;
            dp[i][j][f] = dp[i][j][f] || rec(i + 1, j - k, f || k > dig);
        }
    }
    return dp[i][j][f];
}
string build(ll i, ll j, ll f)
{
    if (i == 401)
        return "";
    ll dig = s[i] - 48;
    for (int k = 0; k < 10; ++k)
    {
        if (k < dig && !f || k > j)
            continue;
        if (rec(i + 1, j - k, f || k > dig) == 1)
        {
            return char(k + 48) + build(i + 1, j - k, f || k > dig);
        }
    }
}
void Sol(){
    cin >> n;
    v.resize(n + 1), res.resize(n + 1);
    res[0] = string(401, '0');
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        memset(dp, -1, sizeof dp);
        s = res[i - 1];
        rec(0, v[i], 0);
        res[i] = build(0, v[i], 0);
        ll ind = 0;
        for (; ind < res[i].size(); ind++) {
            if (res[i][ind] != '0')
                break;
        }
        cout << res[i].substr(ind) << "\n";
    }
}
int main() {
    Fast
    ll T = 1;
    //    cin >> T;
    // cin.ignore();

    while (T--) {
        Sol();
    }

    return 0;
}
