#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'


string S, T;
int N, M;
int dp[3005][3005];

int rec(int i, int j){
    if(i==N||j==M) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(S[i]==T[j]) return dp[i][j]=1+rec(i+1,j+1);
    return dp[i][j]=max(rec(i+1,j),rec(i,j+1));
}

void solve(){
    cin>>S>>T;
    N=S.size(); M=T.size();
    memset(dp,-1,sizeof(dp));
    rec(0,0);

    // Reconstruct
    string lcs="";
    int i=0,j=0;
    while(i<N&&j<M){
        if(S[i]==T[j]){lcs+=S[i];i++;j++;}
        else if(dp[i+1][j]>dp[i][j+1]) i++;
        else j++;
    }
    cout<<lcs<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}