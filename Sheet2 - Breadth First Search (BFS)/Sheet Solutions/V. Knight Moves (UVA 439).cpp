#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int dist[8][8];

void bfs(int sr,int sc,int er,int ec){
    memset(dist,-1,sizeof(dist));

    queue<pair<int,int>>q;
    q.push({sr,sc});
    dist[sr][sc]=0;

    int dx[]={-2,-2,-1,-1,1,1,2,2};
    int dy[]={-1,1,-2,2,-2,2,-1,1};

    while(!q.empty()){
        auto[r,c]=q.front();q.pop();

        if(r==er&&c==ec) return;

        for(int d=0;d<8;d++){
            int nr=r+dx[d],nc=c+dy[d];
            if(nr>=0&&nr<8&&nc>=0&&nc<8&&dist[nr][nc]==-1){
                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
}

void solve(){
    string s,t;
    while(cin>>s>>t){
        int sc=s[0]-'a',sr=s[1]-'1';
        int ec=t[0]-'a',er=t[1]-'1';

        bfs(sr,sc,er,ec);

        cout<<"To get from "<<s<<" to "<<t<<" takes "<<dist[er][ec]<<" knight moves."<<endl;
    }
}

int main(){
    Fast

    solve();
}
