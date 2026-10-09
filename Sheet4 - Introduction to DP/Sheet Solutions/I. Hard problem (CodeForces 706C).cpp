#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'


const ll INF=1e18;
int N;
ll c[100005];
string s[100005], rev[100005];
ll dp[100005][2];

ll rec(int i, int j){
    if(i==0) return j==0 ? 0 : c[0];
    if(dp[i][j]!=-1) return dp[i][j];

    string &cur  = (j==0)?s[i]:rev[i];
    ll cost      = (j==1)?c[i]:0LL;
    ll res=INF;

    // came from i-1 not reversed
    if(cur>=s[i-1]){
        ll prev=rec(i-1,0);
        if(prev!=INF) res=min(res,prev+cost);
    }
    // came from i-1 reversed
    if(cur>=rev[i-1]){
        ll prev=rec(i-1,1);
        if(prev!=INF) res=min(res,prev+cost);
    }
    return dp[i][j]=res;
}

void solve(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>c[i];
    for(int i=0;i<N;i++){
        cin>>s[i];
        rev[i]=s[i];
        reverse(rev[i].begin(),rev[i].end());
    }
    for(int i=0;i<N;i++) dp[i][0]=dp[i][1]=-1;
    ll ans=min(rec(N-1,0),rec(N-1,1));
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}