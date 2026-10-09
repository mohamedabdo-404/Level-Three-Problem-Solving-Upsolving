#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
//1=>527
string s;//527 _ _ _
ll dp[20][2][4];
ll rec(int idx,bool tight,ll cnt){//O(18*2*4*9)
    if(cnt>3)return 0;
    if(idx==s.size()){
        return 1;
    }
    ll &ret=dp[idx][tight][cnt];
    if(ret!=-1){
        return ret;
    }
    ll ans=0;
    ll en=(tight)?s[idx]-'0':9;
        for (int i = 0; i <= en; i++)
        {
            ll newCnt=cnt+(i!=0);
            ans+=rec(idx+1,tight&&((s[idx]-'0')==i),newCnt);
        }
    return ret=ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
   ll l,r;
   cin>>l>>r;
   //(1=>r)-(1=>l)
   s=to_string(r);
   ll ans1=rec(0,1,0);
    memset(dp,-1,sizeof(dp));
    l--;
   s=to_string(l);
    //1=>l
    ll ans2=rec(0,1,0);
    cout<<ans1-ans2<<endl;
}
int main(){
    Fast
    ll T = 1;
    cin >> T;
    // cin.ignore();
    while (T--){
        solve();
    }
}