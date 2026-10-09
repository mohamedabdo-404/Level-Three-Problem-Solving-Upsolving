#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int M, K;
int W[55], V[55];
int dp[55][1005];

int rec(int i, int w){
    if(i==M||w==0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

    int res=rec(i+1,w);
    if(W[i]<=w) res=max(res,V[i]+rec(i+1,w-W[i]));

    return dp[i][w]=res;
}

void solve(){ 
    memset(dp,-1,sizeof(dp));
    cin>>K>>M;
    for(int i=0;i<M;i++) cin>>W[i]>>V[i];
   
    cout<<"Hey stupid robber, you can get "<<rec(0,K)<<"."<<endl;
}

int main(){
    Fast
    ll T=1;
    cin>>T;
    while(T--) solve();
}