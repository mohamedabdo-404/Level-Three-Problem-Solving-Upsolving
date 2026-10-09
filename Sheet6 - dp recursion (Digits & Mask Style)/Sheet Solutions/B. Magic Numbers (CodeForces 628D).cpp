#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
ll m,d;
const ll mod=1e9+7;
string s;
ll dp[2005][2][4000];
ll rec(int idx,bool tight,ll rem){
    if(idx==s.size()){
        return rem==0;
    }
    ll &ret=dp[idx][tight][rem];
    if(ret!=-1){
        return ret;
    }
    ll ans=0;
    ll en=(tight)?s[idx]-'0':9;
        for (int digit = 0; digit <= en; digit++)
        {
            if(idx%2==0){
                if(digit==d){
                    continue;
                }
            }else{
                if(digit!=d){
                    continue;
                }
            }
            ll newRem=((rem*10)+digit)%m;
            ans+=rec(idx+1,tight&&((s[idx]-'0')==digit),newRem);
            ans%=mod;
        }
    return ret=ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
   cin>>m>>d;
   string a,b;
   cin>>a>>b;
   //(1=>b)-(1=>a-1)
   s=b;
   ll ans1=rec(0,1,0);
    memset(dp,-1,sizeof(dp));
    //35=>34
    //200=>199
    int i=a.size()-1;
    while (i>=0&&a[i]=='0')
    {
        a[i]='9';
        i--;
    }
    a[i]--;
    s=a;
   ll ans2=rec(0,1,0);
   cout<<(ans1-ans2+mod)%mod<<endl;
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