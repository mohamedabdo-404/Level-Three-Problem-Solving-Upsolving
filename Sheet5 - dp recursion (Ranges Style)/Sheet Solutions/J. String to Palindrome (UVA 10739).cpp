#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

string s;
int n;
ll dp[1005][1005];
bool vis[1005][1005];

ll rec(int l,int r){
    if(l>=r) return 0;
    if(vis[l][r]) return dp[l][r];
    vis[l][r]=true;
    ll &ret=dp[l][r];
    if(s[l]==s[r]) return ret=rec(l+1,r-1);
    // mismatch: insert/delete skip l, skip r, or substitute both
    return ret=1+min({rec(l+1,r),rec(l,r-1),rec(l+1,r-1)});
}
void solve(){
    int T; cin>>T;
    int cas=1;
    while(T--){
        cin>>s;
        n=s.size();
        memset(vis,false,sizeof(vis));
        cout<<"Case "<<cas++<<": "<<rec(0,n-1)<<endl;
    }
}
int main(){
    Fast
    ll T2=1;
    // cin>>T2;
    // cin.ignore();
    while(T2--){
        solve();
    }
}
