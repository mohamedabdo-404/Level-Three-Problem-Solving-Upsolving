
#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

string s;
int n;
int dp[1005][1005];
bool vis[1005][1005];

int rec(int l, int r){
    if(l > r) return 0;
    if(l == r) return 1;

    if(vis[l][r]) return dp[l][r];
    vis[l][r] = true;

    int &ret = dp[l][r];

    if(s[l] == s[r])
        ret = 2 + rec(l + 1, r - 1);
    else
        ret = max(rec(l + 1, r), rec(l, r - 1));

    return ret;
}

string build(int l, int r, int len){
    if(len == 0 || l > r) return "";

    if(len == 1){
        for(char c = 'a'; c <= 'z'; c++){
            for(int i = l; i <= r; i++){
                if(s[i] == c)
                    return string(1, c);
            }
        }
    }

    for(char c = 'a'; c <= 'z'; c++){
        int L = -1, R = -1;

        for(int i = l; i <= r; i++){
            if(s[i] == c){
                L = i;
                break;
            }
        }

        for(int i = r; i >= l; i--){
            if(s[i] == c){
                R = i;
                break;
            }
        }

        if(L != -1 && R != -1 && L < R){
            if(rec(L + 1, R - 1) == len - 2){
                return string(1, c) +
                       build(L + 1, R - 1, len - 2) +
                       string(1, c);
            }
        }
    }

    return "";
}

void solve(){
    while(cin >> s){
        n = s.size();
        memset(vis, false, sizeof(vis));

        int len = rec(0, n - 1);
        cout << build(0, n - 1, len) << endl;
    }
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
