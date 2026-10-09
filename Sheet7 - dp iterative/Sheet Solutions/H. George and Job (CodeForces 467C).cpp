#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll NEG=-1e18;
void solve(){
    int n,m,K; cin>>n>>m>>K;
    vector<ll>p(n+1),pref(n+1,0);
    for(int i=1;i<=n;i++){cin>>p[i];pref[i]=pref[i-1]+p[i];}
    vector<vector<ll>>dp(n+1,vector<ll>(K+1,NEG));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=K;j++){
            dp[i][j]=dp[i-1][j];// skip element i
            if(j>0&&i>=m&&dp[i-m][j-1]!=NEG)
                dp[i][j]=max(dp[i][j],dp[i-m][j-1]+(pref[i]-pref[i-m]));
        }
    }
    cout<<dp[n][K]<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
