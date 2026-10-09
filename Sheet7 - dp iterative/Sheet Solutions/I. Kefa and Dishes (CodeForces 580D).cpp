#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    ll n,m,k; cin>>n>>m>>k;
    vector<ll>a(n);
    for(auto&x:a) cin>>x;
    vector<vector<ll>>bonus(n,vector<ll>(n,0));
    for(int i=0;i<k;i++){
        ll x,y,b; cin>>x>>y>>b; x--;y--;
        bonus[x][y]=b;
    }
    vector<vector<ll>>dp(1<<n,vector<ll>(n,-1));
    ll ans=0;
    // Initialize: single dish
    for(int i=0;i<n;i++) dp[1<<i][i]=a[i];
    // Fill
    for(int mask=1;mask<(1<<n);mask++){
        if(__builtin_popcount(mask)>m) continue;
        for(int last=0;last<n;last++){
            if(!(mask&(1<<last))||dp[mask][last]<0) continue;
            if(__builtin_popcount(mask)==m){
                ans=max(ans,dp[mask][last]);
                continue;
            }
            for(int nxt=0;nxt<n;nxt++){
                if(mask&(1<<nxt)) continue;
                int nmask=mask|(1<<nxt);
                ll val=dp[mask][last]+a[nxt]+bonus[last][nxt];
                dp[nmask][nxt]=max(dp[nmask][nxt],val);
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
