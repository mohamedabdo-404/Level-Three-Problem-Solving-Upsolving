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

    vector<int>a(n*m);
    for(int i=0;i<n*m;i++) cin>>a[i];

    auto id=[&](int r,int c){return r*m+c;};

    // 0-1 BFS for Eddard from (0,0)
    // Cost to leave cell cur = 0 if a[cur]&2, else 1
    vector<int>distE(n*m,INT_MAX);
    {
        deque<int>dq;
        distE[0]=0;
        dq.push_front(0);
        while(!dq.empty()){
            int cur=dq.front();dq.pop_front();
            int r=cur/m,c=cur%m;
            int w=(a[cur]&2)?0:1;
            for(int d=0;d<4;d++){
                int nr=r+dx[d],nc=c+dy[d];
                if(nr<0||nr>=n||nc<0||nc>=m) continue;
                int nid=id(nr,nc);
                if(distE[cur]+w<distE[nid]){
                    distE[nid]=distE[cur]+w;
                    if(w==0) dq.push_front(nid);
                    else dq.push_back(nid);
                }
            }
        }
    }

    // 0-1 BFS for Partner from (n-1,m-1)
    // Cost to leave cell cur = 0 if a[cur]&1, else 1
    vector<int>distP(n*m,INT_MAX);
    {
        int src=id(n-1,m-1);
        deque<int>dq;
        distP[src]=0;
        dq.push_front(src);
        while(!dq.empty()){
            int cur=dq.front();dq.pop_front();
            int r=cur/m,c=cur%m;
            int w=(a[cur]&1)?0:1;
            for(int d=0;d<4;d++){
                int nr=r+dx[d],nc=c+dy[d];
                if(nr<0||nr>=n||nc<0||nc>=m) continue;
                int nid=id(nr,nc);
                if(distP[cur]+w<distP[nid]){
                    distP[nid]=distP[cur]+w;
                    if(w==0) dq.push_front(nid);
                    else dq.push_back(nid);
                }
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<n*m;i++){
        if(distE[i]!=INT_MAX && distP[i]!=INT_MAX)
            ans=min(ans,distE[i]+distP[i]);
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
