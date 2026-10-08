#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<ll>>adj(200005);

void solve(){
    ll n,k;
    cin>>n>>k;

    vector<int>friendNode(k);
    vector<int>isFriend(n+1,0);
    for(int i=0;i<k;i++){
        cin>>friendNode[i];
        isFriend[friendNode[i]]=1;
    }

    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Multi-source BFS from friends
    vector<int>distF(n+1,-1);
    queue<int>q;
    for(int i=0;i<k;i++){
        distF[friendNode[i]]=0;
        q.push(friendNode[i]);
    }
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto i:adj[cur]){
            if(distF[i]==-1){
                distF[i]=distF[cur]+1;
                q.push(i);
            }
        }
    }

    // BFS from Vlad (node 1)
    vector<int>distV(n+1,-1);
    distV[1]=0;
    queue<int>q2;
    if(distF[1]==-1||distV[1]<distF[1]) q2.push(1);
    // If friends reach node 1 first, Vlad can't even start

    // Check if Vlad is blocked at start
    if(distF[1]!=-1 && distF[1]<=0){
        cout<<"No"<<endl;
        return;
    }
    q2.push(1); // Vlad starts at 1
    // Actually reset:
    while(!q2.empty()) q2.pop();
    q2.push(1);

    while(!q2.empty()){
        int cur=q2.front();q2.pop();
        for(auto i:adj[cur]){
            if(distV[i]==-1){
                distV[i]=distV[cur]+1;
                // Vlad can only reach i if he gets there strictly before friends
                if(distF[i]==-1||distV[i]<distF[i]){
                    q2.push(i);
                }else{
                    distV[i]=-1; // blocked
                }
            }
        }
    }

    // Check if any leaf (degree 1, not node 1) is reachable by Vlad
    bool win=false;
    for(int i=2;i<=n;i++){
        if((int)adj[i].size()==1 && distV[i]!=-1){
            win=true;
            break;
        }
    }

    cout<<(win?"Yes":"No")<<endl;
}

int main(){
    Fast

    ll T=1;
    cin>>T;
    // cin.ignore();

    while(T--){
        for(int i=0;i<200005;i++) adj[i].clear();
        solve();
    }
}
