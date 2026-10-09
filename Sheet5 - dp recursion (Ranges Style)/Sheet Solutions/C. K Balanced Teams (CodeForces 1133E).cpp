#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n,K;
ll a[5005];
int L[5005];   // L[i] = leftmost index for team ending at i
ll dp[5005][5005];
bool vis[5005][5005];

ll rec(int i,int k){
    if(i==0||k==0) return 0;
    if(vis[i][k]) return dp[i][k];
    vis[i][k]=true;
    ll &ret=dp[i][k];
    ret=rec(i-1,k);                          // skip student i
    int len=i-L[i]+1;                        // team size ending at i
    ll take=rec(L[i]-1,k-1)+len;            // use this team
    return ret=max(ret,take);
}
void solve(){
    cin>>n>>K;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    // two pointer: for each i, find smallest j where a[i]-a[j]<=5
    for(int i=1,j=1;i<=n;i++){
        while(a[i]-a[j]>5) j++;
        L[i]=j;
    }
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
