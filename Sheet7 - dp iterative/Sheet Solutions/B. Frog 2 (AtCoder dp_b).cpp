#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll INF=1e18;
void solve(){
    int n,k; cin>>n>>k;
    vector<ll>h(n);
    for(auto&x:h) cin>>x;
    vector<ll>dp(n,INF);
    dp[0]=0;
    for(int i=1;i<n;i++)
        for(int j=1;j<=k&&i-j>=0;j++)
            dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
    cout<<dp[n-1]<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
