#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int N, K;
ll h[100005];
ll dp[100005];

ll recN(int i){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];

    ll res=1e18;
    for(int j=1;j<=K&&i-j>=0;j++)
        res=min(res,recN(i-j)+abs(h[i]-h[i-j]));

    return dp[i]=res;
}

void solve(){
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>h[i];
    memset(dp,-1,sizeof(dp));
    cout<<recN(N-1)<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}