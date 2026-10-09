#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int OFF = 10000;
const int SZ = 20001;
const int INF = -1e9;

int N;
ll K;
int av[105], bv[105], xv[105];
int dp[SZ];

void solve(){
    cin >> N >> K;

    for(int i = 0; i < N; i++) cin >> av[i];

    for(int i = 0; i < N; i++){
        cin >> bv[i];
        xv[i] = av[i] - K * bv[i];
    }

    fill(dp, dp + SZ, INF);
    dp[OFF] = 0;

    for(int i = 0; i < N; i++){
        int ndp[SZ];
        copy(dp, dp + SZ, ndp);

        for(int s = 0; s < SZ; s++){
            if(dp[s] == INF) continue;

            int ns = s + xv[i];

            if(ns >= 0 && ns < SZ){
                ndp[ns] = max(ndp[ns], dp[s] + av[i]);
            }
        }

        copy(ndp, ndp + SZ, dp);
    }

    if(dp[OFF] <= 0) cout << -1 << endl;
    else cout << dp[OFF] << endl;
}

int main(){
    Fast
    ll T = 1;
    // cin >> T;
    while(T--) solve();
}
