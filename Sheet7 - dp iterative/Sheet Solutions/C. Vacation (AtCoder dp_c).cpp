#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    int n; cin>>n;
    vector<array<ll,3>>a(n);
    for(auto&x:a) cin>>x[0]>>x[1]>>x[2];
    vector<array<ll,3>>dp(n,{0,0,0});
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i][1];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+a[i][2];
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
