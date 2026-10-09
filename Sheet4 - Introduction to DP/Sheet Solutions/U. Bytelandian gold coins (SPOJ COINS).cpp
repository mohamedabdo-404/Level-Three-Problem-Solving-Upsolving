#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

map<ll,ll>dp;

ll rec(ll n){
    if(n==0) return 0;
    if(dp.count(n)) return dp[n];
    return dp[n]=max(n, rec(n/2)+rec(n/3)+rec(n/4));
}

int main(){
    Fast
    ll n;
    while(cin>>n) cout<<rec(n)<<endl;
}