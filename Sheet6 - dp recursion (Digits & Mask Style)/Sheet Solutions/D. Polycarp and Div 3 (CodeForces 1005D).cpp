#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll N=200005;
string w;
ll dp[N][5];
ll rec(ll i,ll n){
    if(i==w.size()){
        return 0;
    }
    ll &ret=dp[i][n];
    if(~ret)return ret;
    ret=0;
    if((n*10+(w[i]-'0'))%3==0)
        ret=max(ret,rec(i+1,0)+1);
    else{
        ret=max(ret,rec(i+1,0));
        ret=max(ret, rec(i+1,(n*10+(w[i]-'0'))%3));
    }
    return ret;
}

void Sol() {
    memset(dp,-1,sizeof dp);
    cin>>w;
    cout<<rec(0,0)<<endl;
}

int main() {
    Fast
    ll T = 1;
    //    cin >> T;
    // cin.ignore();

    while (T--) {
        Sol();
    }

    return 0;
}
