#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
ll n,m,k;
ll a[20];
ll bouns[20][20];
ll dp[1<<18][18];
ll rec(ll mask,ll last){//100000000000000000
    if(__builtin_popcount(mask)==m){
        return 0;
    }
    ll &ret=dp[mask][last];
    if(ret!=-1){
        return ret;
    }
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        if(mask&(1<<i)){
            continue;
        }
        ans=max(ans,a[i]+bouns[last][i]+rec(mask|(1<<i),i));
    }
    return ret=ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    for (int i = 0; i < n; i++)
    {
       cin>>a[i];
    }
    for (int i = 0; i < k; i++)
    {
        ll x,y,b;
        cin>>x>>y>>b;
        x--,y--;
        bouns[x][y]=b;
    }
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        ans=max(ans,a[i]+rec(1<<i,i));
    }
    cout<<ans<<endl;
}
int main(){
    Fast
    ll T = 1;
    // cin >> T;
    // cin.ignore();
    while (T--){
        solve();
    }
}