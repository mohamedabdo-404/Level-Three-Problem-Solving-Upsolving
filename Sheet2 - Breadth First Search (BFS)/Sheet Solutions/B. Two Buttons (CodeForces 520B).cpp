#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'
vector<vector<ll>>adj(100005);
vector<int>vis(100005),level(100005);
void bfs(int start){
  queue<int>q;
  q.push(start);
  vis[start]=1;
  level[start]=0;

  while (!q.empty())
  {
     int cur=q.front();
     //n=>m
     //-1
     if((cur-1)>0&& !vis[cur-1]){
      q.push(cur-1);
      vis[cur-1]=1;
      level[cur-1]=level[cur]+1;
     }
     //*2
     if((cur*2)<=20000&& !vis[cur*2]){
      q.push(cur*2);
      vis[cur*2]=1;
      level[cur*2]=level[cur]+1;
     }
    q.pop();
  }
}
void solve(){
  ll n,m;
  cin>>n>>m;
  bfs(n);//O(n+m)
  cout<<level[m]<<endl;
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