#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int N;
ll h[100005];
ll dp[100005];

ll rec(int i){
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];

    ll res=rec(i-1)+abs(h[i]-h[i-1]);
    if(i>=2) res=min(res,rec(i-2)+abs(h[i]-h[i-2]));

    return dp[i]=res;
}

void solve(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>h[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(N-1)<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}