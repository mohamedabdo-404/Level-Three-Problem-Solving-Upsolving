#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int Ni;
ll Wi;
ll wt[105], vl[105];
ll dp[105][100005];

ll rec(int i, ll w){
    if(i==Ni||w==0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

    ll res=rec(i+1,w);              // skip item i
    if(wt[i]<=w)                     // take item i
        res=max(res,vl[i]+rec(i+1,w-wt[i]));

    return dp[i][w]=res;
}

void solve(){
    cin>>Ni>>Wi;
    for(int i=0;i<Ni;i++) cin>>wt[i]>>vl[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,Wi)<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}