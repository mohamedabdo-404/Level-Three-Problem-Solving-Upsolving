#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<int>>adj(26);
vector<int>vis(26);

void solve(ll n){

    ll m;
    cin>>m;

    string s;
    cin>>s;

    for(int i = 0; i < 26; i++){
        adj[i].clear();
        vis[i] = 0;
    }

    for(auto i:s){
        vis[i-'A'] = 1;
    }

    for(int i = 0; i < m; i++){//Undirected

        char x,y;
        cin>>x>>y;

        adj[x-'A'].push_back(y-'A');
        adj[y-'A'].push_back(x-'A');
    }

    ll awake = 3;
    ll years = 0;

    while(awake < n){

        vector<int>temp;

        for(int i = 0; i < 26; i++){

            if(vis[i])
                continue;

            ll cnt = 0;

            for(auto j:adj[i]){

                if(vis[j]){
                    cnt++;
                }
            }

            if(cnt >= 3){
                temp.push_back(i);
            }
        }

        if(temp.empty()){
            cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
            return;
        }

        for(auto i:temp){
            vis[i] = 1;
            awake++;
        }

        years++;
    }

    cout<<"WAKE UP IN, "<<years<<", YEARS"<<endl;
}

int main(){

    Fast

    ll n;

    while(cin>>n){
        solve(n);
    }
}