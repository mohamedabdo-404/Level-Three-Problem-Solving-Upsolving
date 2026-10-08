#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];

    vector<vector<ll>>dist(n,vector<ll>(m,LLONG_MAX));
    dist[0][0]=grid[0][0];

    // Dijkstra on grid: {cost, r, c}
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>>pq;
    pq.push({grid[0][0],0,0});

    while(!pq.empty()){
        auto[d,r,c]=pq.top();pq.pop();
        if(d!=dist[r][c]) continue;

        for(int i=0;i<4;i++){
            int nr=r+dx[i],nc=c+dy[i];
            if(nr<0||nr>=n||nc<0||nc>=m) continue;
            ll nd=d+grid[nr][nc];
            if(nd<dist[nr][nc]){
                dist[nr][nc]=nd;
                pq.push({nd,nr,nc});
            }
        }
    }

    cout<<dist[n-1][m-1]<<endl;
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
