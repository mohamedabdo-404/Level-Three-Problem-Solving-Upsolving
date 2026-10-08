#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void solve(){

    ll n,m;
    cin>>n>>m;

    vector<string>grid(n);

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    //Find Start

    int sx=0,sy=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j]=='H'){
                sx=i;
                sy=j;
            }
        }
    }

    // vis[x][y][0] -> doors closed
    // vis[x][y][1] -> doors open
    vector<vector<vector<int>>>vis(
        n,vector<vector<int>>(m,vector<int>(2,0))
    );

    queue<tuple<int,int,int>>q;

    q.push({sx,sy,0});
    vis[sx][sy][0]=1;

    int steps=0;

    while(!q.empty()){

        int sz=q.size();

        while(sz--){

            auto [x,y,open]=q.front();
            q.pop();

            
            if(x==0 || x==n-1 || y==0 || y==m-1){
                cout<<steps+1<<endl;
                return;
            }

            for(int d=0;d<4;d++){

                int nx=x+dx[d];
                int ny=y+dy[d];

                if(nx<0 || nx>=n || ny<0 || ny>=m){
                    continue;
                }

                if(grid[nx][ny]=='W'){
                    continue;
                }

                // Door is closed
                if(grid[nx][ny]=='D' && !open){
                    continue;
                }

                int nopen=open;

                // Opening button
                if(grid[nx][ny]=='O'){
                    nopen=1;
                }

                // Closing button
                if(grid[nx][ny]=='C'){
                    nopen=0;
                }

                if(!vis[nx][ny][nopen]){

                    vis[nx][ny][nopen]=1;
                    q.push({nx,ny,nopen});
                }
            }
        }

        steps++;
    }

    cout<<-1<<endl;
}

int main(){

    Fast

    while(true){

        ll n,m;
        cin>>n>>m;

        if(n==-1 && m==-1){
            break;
        }

        // solve needs the dimensions again
        // so handle the test case directly

        vector<string>grid(n);

        for(int i=0;i<n;i++){
            cin>>grid[i];
        }

        int sx=0,sy=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='H'){
                    sx=i;
                    sy=j;
                }
            }
        }

        vector<vector<vector<int>>>vis(
            n,vector<vector<int>>(m,vector<int>(2,0))
        );

        queue<tuple<int,int,int>>q;

        q.push({sx,sy,0});
        vis[sx][sy][0]=1;

        int steps=0;
        bool escaped=false;

        while(!q.empty() && !escaped){

            int sz=q.size();

            while(sz--){

                auto [x,y,open]=q.front();
                q.pop();

                if(x==0 || x==n-1 || y==0 || y==m-1){

                    cout<<steps+1<<endl;
                    escaped=true;
                    break;
                }

                for(int d=0;d<4;d++){

                    int nx=x+dx[d];
                    int ny=y+dy[d];

                    if(nx<0 || nx>=n || ny<0 || ny>=m){
                        continue;
                    }

                    if(grid[nx][ny]=='W'){
                        continue;
                    }

                    if(grid[nx][ny]=='D' && !open){
                        continue;
                    }

                    int nopen=open;

                    if(grid[nx][ny]=='O'){
                        nopen=1;
                    }

                    if(grid[nx][ny]=='C'){
                        nopen=0;
                    }

                    if(!vis[nx][ny][nopen]){

                        vis[nx][ny][nopen]=1;
                        q.push({nx,ny,nopen});
                    }
                }
            }

            steps++;
        }

        if(!escaped){
            cout<<-1<<endl;
        }
    }
}