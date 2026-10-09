
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int MAXN = 30001, OFF = 250, MAXO = 501;
int gem[MAXN];
int dp[MAXN][MAXO];
int D;

int rec(int pos, int o){
    if(pos >= MAXN) return 0;
    if(o < 0 || o >= MAXO) return 0;

    if(dp[pos][o] != -1) return dp[pos][o];

    int len = D + o - OFF;
    int best = 0;

    for(int delta = -1; delta <= 1; delta++){
        int nlen = len + delta;
        if(nlen <= 0) continue;

        int ni = pos + nlen;
        int no = o + delta;

        if(ni >= MAXN || no < 0 || no >= MAXO) continue;

        best = max(best, rec(ni, no));
    }

    return dp[pos][o] = gem[pos] + best;
}

void solve(){
    int n;
    cin >> n >> D;

    memset(gem, 0, sizeof(gem));

    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        gem[p]++;
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(D, OFF) << endl;
}

int main(){
    Fast
    ll T = 1;
    // cin >> T;
    while(T--) solve();
}
