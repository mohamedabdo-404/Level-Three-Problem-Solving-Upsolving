#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'


ll a[200005];
ll dp[200005];

ll rec(int i){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=rec(i-1)+a[i];
}

void solve(){
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    // precompute all
    for(int i=1;i<=n;i++) rec(i);

    while(q--){
        ll l,r; cin>>l>>r;
        cout<<dp[r]-dp[l-1]<<endl;
    }
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}