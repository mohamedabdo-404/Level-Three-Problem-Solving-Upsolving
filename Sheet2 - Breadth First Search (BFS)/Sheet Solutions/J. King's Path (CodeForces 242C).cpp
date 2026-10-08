#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'


void solve(){
    int x0,y0,x1,y1;
    cin>>x0>>y0>>x1>>y1;

    int n;
    cin>>n;

    set<pair<int,int>>allowed;
    for(int i=0;i<n;i++){
        int r,a,b;
        cin>>r>>a>>b;
        for(int j=a;j<=b;j++){
            allowed.insert({r,j});
        }
    }

    // BFS
    map<pair<int,int>,int>dist;
    queue<pair<int,int>>q;

    pair<int,int>start={x0,y0};
    pair<int,int>target={x1,y1};

    if(!allowed.count(start)||!allowed.count(target)){
        cout<<-1<<endl;
        return;
    }

    dist[start]=0;
    q.push(start);

    int dx[]={-1,-1,-1,0,0,1,1,1};
    int dy[]={-1,0,1,-1,1,-1,0,1};

    while(!q.empty()){
        auto[r,c]=q.front();
        q.pop();

        if(r==x1&&c==y1){
            cout<<dist[target]<<endl;
            return;
        }

        for(int d=0;d<8;d++){
            int nr=r+dx[d],nc=c+dy[d];
            pair<int,int>nxt={nr,nc};
            if(allowed.count(nxt)&&!dist.count(nxt)){
                dist[nxt]=dist[{r,c}]+1;
                q.push(nxt);
            }
        }
    }

    cout<<-1<<endl;
}

int main(){
    Fast

    ll T=1;
    // cin>>T;
    // cin.ignore();

    while(T--){
        solve();
    }
}
