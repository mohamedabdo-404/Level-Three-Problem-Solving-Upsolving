#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        int n=s.size();
        vector<ll>dp(n+1,0);
        // dp[n] = 0 (empty suffix)
        for(int i=n-1;i>=0;i--){
            dp[i]=0;
            ll num=0;
            for(int j=i;j<n;j++){
                num=num*10+(s[j]-'0');
                if(num>(ll)INT_MAX) break;
                dp[i]=max(dp[i],num+dp[j+1]);
                if(num==0) break; // leading zero: only "0" is valid
            }
        }
        cout<<dp[0]<<endl;
    }
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
