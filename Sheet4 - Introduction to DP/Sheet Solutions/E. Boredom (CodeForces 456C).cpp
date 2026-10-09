#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int MAXV=100005;
ll cnt[MAXV];
ll dp[MAXV];

ll rec(int i){
    if(i<=0) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(rec(i-1), rec(i-2)+1LL*i*cnt[i]);
}

void solve(){
    ll n; cin>>n;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){int x;cin>>x;cnt[x]++;}
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    cout<<rec(MAXV-1)<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}