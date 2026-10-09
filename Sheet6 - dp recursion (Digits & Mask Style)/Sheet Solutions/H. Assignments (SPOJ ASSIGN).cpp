#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int n;
int a[20][20];
ll dp[1<<20];
bool vis[1<<20];

ll rec(int mask){
    if(mask==(1<<n)-1) return 1; // all topics assigned
    if(vis[mask]) return dp[mask];
    vis[mask]=true;
    ll &ret=dp[mask];
    ret=0;
    int student=__builtin_popcount(mask); // next student to assign
    for(int j=0;j<n;j++){
        if(mask&(1<<j)) continue;   // topic j already used
        if(a[student][j]==1)         // student likes topic j
            ret+=rec(mask|(1<<j));
    }
    return ret;
}
void Sol(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    memset(vis,false,sizeof(vis));
    cout<<rec(0)<<endl;
}
int main(){
    Fast
    ll T=1;
    cin>>T;
    // cin.ignore();
    while(T--){
        Sol();
    }
}
