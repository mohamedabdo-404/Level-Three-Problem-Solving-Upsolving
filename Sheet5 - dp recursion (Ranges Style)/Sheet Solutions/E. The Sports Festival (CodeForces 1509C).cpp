#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n;
ll s[5005];
ll dp[5005][5005];
bool vis[5005][5005];

ll rec(int l,int r){
    if(l==r) return 0;
    if(vis[l][r]) return dp[l][r];
    vis[l][r]=true;
    ll &ret=dp[l][r];
    return ret=(s[r]-s[l])+min(rec(l+1,r),rec(l,r-1));
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s,s+n);
    memset(vis,false,sizeof(vis));
    cout<<rec(0,n-1)<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--){
        solve();
    }
}
