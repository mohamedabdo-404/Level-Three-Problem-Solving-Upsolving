#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int T,A,N;
int o[1005],a[1005],w[1005];
// States: (item, need_o, need_n). need_o<=21, need_n<=79
int dp[1005][22][80];

int rec(int i, int o, int n){
    if(o<=0&&n<=0) return 0;
    if(i==N) return 1e9;
    if(dp[i][o][n]!=-1) return dp[i][o][n];

    int skip=rec(i+1,o,n);
    int take=w[i]+rec(i+1,max(0,o-o[i]),max(0,n-a[i]));

    return dp[i][o][n]=min(skip,take);
}

void solve(){
    cin>>T>>A>>N;
    for(int i=0;i<N;i++) cin>>o[i]>>a[i]>>w[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,T,A)<<endl;
}

int main(){
    Fast
    ll T=1;
    cin>>T;
    while(T--) solve();
}