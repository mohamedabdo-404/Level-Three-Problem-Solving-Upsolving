
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int C;
ll a[105], p[105], psum[105];
ll dp3[105];
bool vis3[105];

ll rec(int i){
    if(i == 0) return 0;

    if(vis3[i]) return dp3[i];
    vis3[i] = true;

    ll &ret = dp3[i];
    ret = 1e18;

    for(int j = 0; j < i; j++){
        ll cost = (psum[i] - psum[j] + 10) * p[i];
        ret = min(ret, rec(j) + cost);
    }

    return ret;
}

void solve(){
    cin >> C;

    psum[0] = 0;
    for(int i = 1; i <= C; i++){
        cin >> a[i] >> p[i];
        psum[i] = psum[i - 1] + a[i];
    }

    memset(vis3, false, sizeof(vis3));
    cout << rec(C) << endl;
}

int main(){
    Fast
    int T;
    cin >> T;
    // cin.ignore();
    while(T--){
        solve();
    }
}
