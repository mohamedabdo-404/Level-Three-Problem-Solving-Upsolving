#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int MOD2=1e8;
int N1,N2,K1,K2;
int dp[105][105][2][105];

int rec(int f,int h,int t,int c){
    if(f<0||h<0) return 0;
    if(f==0&&h==0) return 1;
    if(dp[f][h][t][c]!=-1) return dp[f][h][t][c];

    int res=0;
    // Add footman
    if(f>0){
        int nc=(t==0)?c+1:1;
        if(nc<=K1) res=(res+rec(f-1,h,0,nc))%MOD2;
    }
    // Add horseman
    if(h>0){
        int nc=(t==1)?c+1:1;
        if(nc<=K2) res=(res+rec(f,h-1,1,nc))%MOD2;
    }
    return dp[f][h][t][c]=res;
}

void solve(){
    cin>>N1>>N2>>K1>>K2;
    memset(dp,-1,sizeof(dp));
    // Start: pick first soldier (both types available at c=0 => use dummy t=2)
    // Actually sum both starting options:
    int ans=0;
    if(N1>0) ans=(ans+rec(N1-1,N2,0,1))%MOD2;
    if(N2>0) ans=(ans+rec(N1,N2-1,1,1))%MOD2;
    cout<<ans<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}