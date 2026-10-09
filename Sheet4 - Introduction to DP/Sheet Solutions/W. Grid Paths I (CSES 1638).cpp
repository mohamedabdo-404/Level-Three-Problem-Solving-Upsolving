#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int MOD=1e9+7;
int N;
string grid[1005];
ll dp[1005][1005];

ll rec(int i, int j){
    if(i==N-1&&j==N-1) return 1;
    if(i>=N||j>=N) return 0;
    if(grid[i][j]=='*') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=(rec(i+1,j)+rec(i,j+1))%MOD;
}

void solve(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>grid[i];
    memset(dp,-1,sizeof(dp));
    if(grid[0][0]=='*'||grid[N-1][N-1]=='*'){cout<<0<<endl;return;}
    cout<<rec(0,0)<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}