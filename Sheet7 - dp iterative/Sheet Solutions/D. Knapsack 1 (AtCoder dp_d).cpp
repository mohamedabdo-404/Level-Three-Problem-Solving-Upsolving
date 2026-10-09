#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    int n; ll W; cin>>n>>W;
    vector<ll>w(n),v(n);
    for(int i=0;i<n;i++) cin>>w[i]>>v[i];
    vector<ll>dp(W+1,0);
    for(int i=0;i<n;i++)
        for(ll j=W;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    cout<<dp[W]<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
