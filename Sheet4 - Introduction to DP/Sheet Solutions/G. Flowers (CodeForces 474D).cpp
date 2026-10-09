#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int MOD3=1e9+7;
const int MXV=100005;
int Kf;
ll dp[MXV], pre[MXV];

ll rec(int i){
    if(i<0)  return 0;
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];
    ll res=rec(i-1);
    if(i>=Kf) res=(res+rec(i-Kf))%MOD3;
    return dp[i]=res;
}

void solve(){
    ll n;
    cin>>n>>Kf;
    memset(dp,-1,sizeof(dp));
    // Precompute all dp values
    for(int i=0;i<MXV;i++) rec(i);
    pre[0]=dp[0];
    for(int i=1;i<MXV;i++) pre[i]=(pre[i-1]+dp[i])%MOD3;

    for(int i=0;i<n;i++){
        ll a,b; cin>>a>>b;
        cout<<(pre[b]-pre[a-1]+MOD3)%MOD3<<endl;
    }
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}