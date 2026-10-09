#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int MOD=1e9+7;
int N,K,D;
ll dp[105][2];

ll rec(int sum, int flag){
    if(sum==N) return flag;
    if(sum>N)  return 0;
    if(dp[sum][flag]!=-1) return dp[sum][flag];

    ll res=0;
    for(int e=1;e<=K;e++){
        res=(res+rec(sum+e, flag|(e>=D?1:0)))%MOD;
    }
    return dp[sum][flag]=res;
}

void solve(){
    cin>>N>>K>>D;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}