#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll INF=1e18;
void solve(){
    int n; cin>>n;
    vector<ll>a(n),pref(n+1,0);
    for(int i=0;i<n;i++){cin>>a[i];pref[i+1]=pref[i]+a[i];}
    vector<vector<ll>>dp(n,vector<ll>(n,INF));
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int len=2;len<=n;len++){
        for(int l=0;l+len-1<n;l++){
            int r=l+len-1;
            ll cost=pref[r+1]-pref[l];
            for(int mid=l;mid<r;mid++)
                dp[l][r]=min(dp[l][r],dp[l][mid]+dp[mid+1][r]+cost);
        }
    }
    cout<<dp[0][n-1]<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
