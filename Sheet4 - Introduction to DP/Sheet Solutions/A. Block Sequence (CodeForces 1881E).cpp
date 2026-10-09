#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n;
ll a[200005];
ll dp[200005];

ll rec(int i){
    if(i>n) return 0;
    if(dp[i]!=-1) return dp[i];

    ll res=1+rec(i+1);               // option 1: remove a[i]
    if(i+a[i]+1<=n+1)              // option 2: keep as block start
        res=min(res,rec(i+a[i]+1));

    return dp[i]=res;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(1)<<endl;
}

int main(){
    Fast
    ll T=1;
    cin>>T;
    while(T--) solve();
}