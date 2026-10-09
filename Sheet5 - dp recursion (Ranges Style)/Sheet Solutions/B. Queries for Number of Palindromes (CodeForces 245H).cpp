#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
string s;
bool dp[5000][5000],vis[5000][5000];
bool isPal(int l,int r){//O(n*n)
    if(l>=r){
        return true;
    }
    if(vis[l][r]){
        return dp[l][r];
    }
    vis[l][r]=true;

    return dp[l][r]=(s[l]==s[r])&&isPal(l+1,r-1);
}
int dp2[5000][5000],vis2[5000][5000];
int countPal(int l,int r){//O(n*n)
    if(l>r){
        return 0;
    }
    if(vis2[l][r]){
        return dp2[l][r];
    }
    vis2[l][r]=true;
    int ch1=countPal(l+1,r);
    int ch2=countPal(l,r-1);
    int ch3=countPal(l+1,r-1);
    return dp2[l][r]=(ch1+ch2-ch3+isPal(l,r));
}
void solve(){
   cin>>s;
   int q;
   cin>>q;
   while (q--)
   {
    int l,r;
    cin>>l>>r;
    l--,r--;
    cout<<countPal(l,r)<<endl;
   }
   
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