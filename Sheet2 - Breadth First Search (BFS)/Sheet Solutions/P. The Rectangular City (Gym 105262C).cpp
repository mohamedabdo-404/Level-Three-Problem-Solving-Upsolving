#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

const int INF=1e9;

vector<vector<int>>adj(1000005);
vector<int>dist(1000005);

void bfs(int start,vector<int>&d,int n,int m){//O(n*m)

    queue<int>q;

    q.push(start);
    d[start]=0;

    while(!q.empty()){

        int cur=q.front();
        q.pop();

        int x=cur/m;
        int y=cur%m;

        for(auto i:adj[cur]){

            if(d[i]==INF){
                d[i]=d[cur]+1;
                q.push(i);
            }
        }
    }
}

void solve(){

    ll n,m,k;
    cin>>n>>m>>k;

    vector<string>grid(n);

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    string p;
    cin>>p;

    //Build Grid Graph

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            int cur=i*m+j;

            if(i>0){
                adj[cur].push_back(cur-m);
            }

            if(i+1<n){
                adj[cur].push_back(cur+m);
            }

            if(j>0){
                adj[cur].push_back(cur-1);
            }

            if(j+1<m){
                adj[cur].push_back(cur+1);
            }
        }
    }

    //BFS for Every Character

    vector<vector<int>>mn(26,vector<int>(26,INF));

    for(int c=0;c<26;c++){

        vector<int>d(n*m,INF);
        queue<int>q;

        // Multi-source BFS
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]-'a'==c){

                    int cur=i*m+j;

                    d[cur]=0;
                    q.push(cur);
                }
            }
        }

        while(!q.empty()){

            int cur=q.front();
            q.pop();

            int x=cur/m;
            int y=cur%m;

            if(x>0){

                int nxt=cur-m;

                if(d[nxt]>d[cur]+1){
                    d[nxt]=d[cur]+1;
                    q.push(nxt);
                }
            }

            if(x+1<n){

                int nxt=cur+m;

                if(d[nxt]>d[cur]+1){
                    d[nxt]=d[cur]+1;
                    q.push(nxt);
                }
            }

            if(y>0){

                int nxt=cur-1;

                if(d[nxt]>d[cur]+1){
                    d[nxt]=d[cur]+1;
                    q.push(nxt);
                }
            }

            if(y+1<m){

                int nxt=cur+1;

                if(d[nxt]>d[cur]+1){
                    d[nxt]=d[cur]+1;
                    q.push(nxt);
                }
            }
        }

        // Get minimum distance to every character
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int to=grid[i][j]-'a';

                mn[c][to]=min(mn[c][to],d[i*m+j]);
            }
        }
    }

    ll ans=0;

    for(int i=1;i<k;i++){

        int from=p[i-1]-'a';
        int to=p[i]-'a';

        ans+=mn[from][to];
    }

    cout<<ans<<endl;
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