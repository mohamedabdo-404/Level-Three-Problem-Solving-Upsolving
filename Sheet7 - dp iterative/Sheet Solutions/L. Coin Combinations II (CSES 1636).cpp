#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
const ll MOD=1e9+7;
void solve(){
    int n; ll x; cin>>n>>x;
    vector<ll>c(n);
    for(auto&v:c) cin>>v;
    vector<ll>dp(x+1,0);
    dp[0]=1;
    for(ll coin:c)
        for(ll s=coin;s<=x;s++)
            dp[s]=(dp[s]+dp[s-coin])%MOD;
    cout<<dp[x]<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
