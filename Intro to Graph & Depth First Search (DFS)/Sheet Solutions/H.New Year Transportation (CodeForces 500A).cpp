#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){

    ll n,t;
    cin>>n>>t;

    vector<ll>a(n);

    for(int i = 1; i < n; i++){
        cin>>a[i];
    }

    ll node = 1;

    while(node < t){
        node += a[node];
    }

    if(node == t){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    cout<<endl;
}

int main(){

    Fast

    ll T = 1;
    // cin >> T;
    // cin.ignore();

    while(T--){
        solve();
    }
}