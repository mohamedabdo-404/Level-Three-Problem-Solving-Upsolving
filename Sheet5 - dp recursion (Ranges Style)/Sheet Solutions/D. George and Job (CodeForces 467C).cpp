#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n,m,K;
ll p[5005],pref[5005];
ll dp[5005][5005];
bool vis[5005][5005];

ll rec(int i,int j){
    if(j==0) return 0;
    if(i<m) return (ll)-1e18;          // not enough elements
    if(vis[i][j]) return dp[i][j];
    vis[i][j]=true;
    ll &ret=dp[i][j];
    ll skip=rec(i-1,j);                // don't end segment at i
    ll take=rec(i-m,j-1)+(pref[i]-pref[i-m]); // segment [i-m+1..i]
    return ret=max(skip,take);
}
void solve(){
    cin>>n>>m>>K;
    for(int i=1;i<=n;i++){cin>>p[i];pref[i]=pref[i-1]+p[i];}
    memset(vis,false,sizeof(vis));
    cout<<rec(n,K)<<endl;
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
