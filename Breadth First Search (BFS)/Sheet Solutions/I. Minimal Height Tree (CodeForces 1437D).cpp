#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){

    ll n;
    cin>>n;

    vector<int>seq(n+1);

    for(int i=1;i<=n;i++){
        cin>>seq[i];
    }

    ll cur=1;
    ll child=0;
    ll ans=0;
    ll i=2;

    while(cur){

        if(i<=n){
            child++;
        }

        i++;

        while(i<=n && seq[i]>seq[i-1]){
            child++;
            i++;
        }

        cur--;

        if(cur==0){
            ans++;
            cur=child;
            child=0;
        }
    }

    cout<<ans-1<<endl;
}

int main(){

    Fast

    ll T=1;
    cin>>T;
    // cin.ignore();

    while(T--){
        solve();
    }
}