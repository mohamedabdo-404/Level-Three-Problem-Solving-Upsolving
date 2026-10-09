#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int N;
ll a[100005], b[100005], c[100005];
ll dp[100005][4];

ll rec(int i, int last){
    if(i==N) return 0;
    if(dp[i][last]!=-1) return dp[i][last];

    ll res=0;
    if(last!=0) res=max(res,a[i]+rec(i+1,0));
    if(last!=1) res=max(res,b[i]+rec(i+1,1));
    if(last!=2) res=max(res,c[i]+rec(i+1,2));

    return dp[i][last]=res;
}

void solve(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i]>>b[i]>>c[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,3)<<endl; // 3 = n restriction at start
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}