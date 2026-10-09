
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int N;
int a[100005];
int dp[100005];

int rec(int i){
    if(dp[i] != -1) return dp[i];

    dp[i] = 1;
    for(int j = i + 1; j < N; j++)
        if(a[j] > a[i])
            dp[i] = max(dp[i], 1 + rec(j));

    return dp[i];
}

void solve(){
    while(cin >> N && N){
        for(int i = 0; i < N; i++) cin >> a[i];

        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for(int i = 0; i < N; i++)
            ans = max(ans, rec(i));

        vector<int> v;
        int pos = 0, last = INT_MIN, rem = ans;

        while(rem > 0){
            int idx = -1;

            for(int i = pos; i < N; i++){
                if(a[i] > last && dp[i] >= rem){
                    if(idx == -1 || a[i] < a[idx])
                        idx = i;
                }
            }

            v.push_back(a[idx]);
            last = a[idx];
            pos = idx + 1;
            rem--;
        }

        cout << ans;
        for(int x : v) cout << ' ' << x;
        cout << endl;
    }
}

int main(){
    Fast
    ll T = 1;
    // cin >> T;
    while(T--) solve();
}
