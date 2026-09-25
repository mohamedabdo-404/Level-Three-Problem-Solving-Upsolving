#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<ll>>adj(100005);
vector<int>vis(100005);
//1=> set1
//2=> set2
ll cnt1=0;
ll cnt2=0;
void dfs(int node,int color){//O(n+m)
  vis[node]=1;
  if(color==1){
    cnt1++;
  }else{//color==2
    cnt2++;
  }
  for(auto i:adj[node]){
    if(!vis[i])
     { 
      dfs(i,(color==1)?2:1);
     }
    }
}
void solve(){
  ll n;
  cin>>n;
  
  for (int i = 0; i < n-1; i++)//Directed
  {
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1,1);//O(n+m)
  ll ans=cnt1*cnt2-(n-1);
  cout<<ans<<endl;
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