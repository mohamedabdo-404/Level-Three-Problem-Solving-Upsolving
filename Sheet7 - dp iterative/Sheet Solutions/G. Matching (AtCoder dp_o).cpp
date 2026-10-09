#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll MOD=1e9+7;
void solve(){
    int n; cin>>n;
    vector<vector<int>>a(n,vector<int>(n));
    for(auto&r:a) for(auto&x:r) cin>>x;
    vector<ll>dp(1<<n,0);
    dp[0]=1;
    for(int mask=0;mask<(1<<n);mask++){
        int man=__builtin_popcount(mask); // next man to assign
        if(man==n) continue;
        for(int j=0;j<n;j++){
            if(mask&(1<<j)) continue;
            if(a[man][j]==1)
                dp[mask|(1<<j)]=(dp[mask|(1<<j)]+dp[mask])%MOD;
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
