#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int N,H,L,R;
int a[200005];
int dp[2005][2005];

int rec(int i, int t){
    if(i>N) return 0;
    if(dp[i][t]!=-1) return dp[i][t];

    int t1=(t+a[i])%H;
    int t2=(t+a[i]-1+H)%H;
    int b1=(t1>=L&&t1<=R)?1:0;
    int b2=(t2>=L&&t2<=R)?1:0;

    int res=max(b1+rec(i+1,t1), b2+rec(i+1,t2));
    return dp[i][t]=res;
}

void solve(){
    cin>>N>>H>>L>>R;
    for(int i=1;i<=N;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0)<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}