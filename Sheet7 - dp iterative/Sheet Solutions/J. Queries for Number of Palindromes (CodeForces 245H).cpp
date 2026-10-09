#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    string s; cin>>s;
    int n=s.size();
    vector<vector<bool>>isPal(n,vector<bool>(n,false));
    vector<vector<ll>>cnt(n,vector<ll>(n,0));
    // Build isPal bottom-up
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l==r) isPal[l][r]=true;
            else if(l+1==r) isPal[l][r]=(s[l]==s[r]);
            else isPal[l][r]=(s[l]==s[r])&&isPal[l+1][r-1];
        }
    }
    // Build countPal bottom-up
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            cnt[l][r]=isPal[l][r];
            if(l+1<=r) cnt[l][r]+=cnt[l+1][r];
            if(l<=r-1) cnt[l][r]+=cnt[l][r-1];
            if(l+1<=r-1) cnt[l][r]-=cnt[l+1][r-1];
        }
    }
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r; l--;r--;
        cout<<cnt[l][r]<<endl;
    }
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--) solve();
}
