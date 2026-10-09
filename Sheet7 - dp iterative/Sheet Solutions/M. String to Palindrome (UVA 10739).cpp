#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    int T; cin>>T;
    int cas=1;
    while(T--){
        string s; cin>>s;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // Build bottom-up: increasing interval length
        for(int len=2;len<=n;len++){
            for(int l=0;l+len-1<n;l++){
                int r=l+len-1;
                if(s[l]==s[r]) dp[l][r]=dp[l+1][r-1];
                else dp[l][r]=1+min({dp[l+1][r],dp[l][r-1],dp[l+1][r-1]});
            }
        }
        cout<<"Case "<<cas++<<": "<<dp[0][n-1]<<endl;
    }
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
