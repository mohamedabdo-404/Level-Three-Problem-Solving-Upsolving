#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n;
int c[505];
ll dp[505][505];
bool vis[505][505];

ll rec(int l,int r){
    if(l>r) return 0;
    if(l==r) return 1;
    if(vis[l][r]) return dp[l][r];
    vis[l][r]=true;
    ll &ret=dp[l][r];
    ret=1e18;
    if(c[l]==c[r]) ret=min(ret,rec(l+1,r-1));  // extend palindrome inward
    for(int mid=l;mid<r;mid++)
        ret=min(ret,rec(l,mid)+rec(mid+1,r));
    if(ret==0) ret=1; // single char base guard
    return ret;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>c[i];
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
