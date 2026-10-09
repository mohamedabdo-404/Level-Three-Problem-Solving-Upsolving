#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

string s;
int n;
ll dp2[205];
bool vis2[205];

ll rec(int i){
    if(i==n) return 0;
    if(vis2[i]) return dp2[i];
    vis2[i]=true;
    ll &ret=dp2[i];
    ret=0;
    ll num=0;
    for(int j=i;j<n;j++){
        num=num*10+(s[j]-'0');
        if(num>(ll)INT_MAX) break;  // exceeded 32-bit
        ret=max(ret,num+rec(j+1));
        if(num==0) break;           // leading zero: only "0" valid
    }
    return ret;
}
void solve(){
    int T; cin>>T;
    while(T--){
        cin>>s;
        n=s.size();
        memset(vis2,false,sizeof(vis2));
        cout<<rec(0)<<endl;
    }
}
int main(){
    Fast
    ll T2=1;
    // cin>>T2;
    // cin.ignore();
    while(T2--){
        solve();
    }
}
