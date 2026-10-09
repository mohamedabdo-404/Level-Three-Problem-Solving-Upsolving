#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
ll n;
vector<ll>a(400),pref(400);
ll dp[400][400];
ll rec(int l,int r){//O(n*n*n)
    if(l>=r){
        return 0;
    }
    ll & ret=dp[l][r];
    if(ret!=-1){
        return ret;
    }
    ll ans=1e15;
    for (int mid = l; mid < r; mid++)//O(n)
    {
        ans=min(ans,rec(l,mid)+rec(mid+1,r)+pref[r]-((l)?pref[l-1]:0));
    }
    return ret=ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
  cin>>n;
  for (int i = 0; i < n; i++)
  {
    cin>>a[i];
    if(i==0){
        pref[i]=a[i];
    }else{
        pref[i]=pref[i-1]+a[i];
    }
  }
  cout<<rec(0,n-1)<<endl;
}
int main(){
    Fast
    ll T = 1;
    // cin >> T;
    // cin.ignore();
    while (T--){
        solve();
    }
}