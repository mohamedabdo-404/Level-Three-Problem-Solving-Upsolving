#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n, a[150005];
int dp[150005][3];

// rec(i, last): min rest days from day i onward, last activity = last
int rec(int i, int last){
    if(i>n) return 0;
    if(dp[i][last]!=-1) return dp[i][last];

    int res=1+rec(i+1,0);           // rest on day i

    if((a[i]==1||a[i]==3)&&last!=1) // contest
        res=min(res,rec(i+1,1));

    if((a[i]==2||a[i]==3)&&last!=2) // sport
        res=min(res,rec(i+1,2));

    return dp[i][last]=res;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0)<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}