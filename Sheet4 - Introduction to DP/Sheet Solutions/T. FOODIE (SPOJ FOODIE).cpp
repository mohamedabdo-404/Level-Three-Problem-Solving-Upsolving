
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int N, K;
int v[1005];
int dp[105][1005];

int rec(int i, int w){
    if(i == N || w == 0) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    int res = rec(i + 1, w);            // skip rack i
    if(v[i] <= w)                       // take rack i
        res = max(res, v[i] + rec(i + 1, w - v[i]));

    return dp[i][w] = res;
}

void solve(){
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int r, sum = 0;
        cin >> r;

        for(int j = 0; j < r; j++){
            int x;
            cin >> x;
            sum += x;
        }

        v[i] = sum;
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, K) << endl;
}

int main(){
    Fast
    ll T = 1;
    cin >> T;
    while(T--) solve();
}
