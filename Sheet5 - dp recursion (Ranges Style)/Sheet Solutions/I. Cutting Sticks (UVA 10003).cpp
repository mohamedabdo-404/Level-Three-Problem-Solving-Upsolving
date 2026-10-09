#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int L,N;
int cuts[55];
ll dp[55][55];
bool vis[55][55];

ll rec(int i,int j){
    if(j<=i+1) return 0;   // no cut between i and j
    if(vis[i][j]) return dp[i][j];
    vis[i][j]=true;
    ll &ret=dp[i][j];
    ret=1e18;
    for(int k=i+1;k<j;k++)
        ret=min(ret,rec(i,k)+rec(k,j)+(cuts[j]-cuts[i]));
    return ret;
}
void solve(){
    while(cin>>L&&L){
        cin>>N;
        cuts[0]=0;
        for(int i=1;i<=N;i++) cin>>cuts[i];
        cuts[N+1]=L;
        memset(vis,false,sizeof(vis));
        cout<<"The minimum cutting is "<<rec(0,N+1)<<"."<<endl;
    }
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
