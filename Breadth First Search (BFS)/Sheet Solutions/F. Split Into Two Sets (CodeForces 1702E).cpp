#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<int>> adj(200005);
vector<int> color(200005,-1);

bool bfsCheck(int start){//O(n+m)
    queue<int>q;
    q.push(start);
    color[start]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(auto i:adj[cur]){
            if(color[i]==-1){
                color[i]=1-color[cur];
                q.push(i);
            }else if(color[i]==color[cur]){
                return false; // odd cycle => not bipartite
            }
        }
    }

    return true;
}

void solve(){
    ll n;
    cin>>n;

    for(int i=1;i<=n;i++){
        adj[i].clear();
        color[i]=-1;
    }

    vector<int>cnt(n+1,0);
    vector<pair<int,int>>dom(n);

    for(int i=0;i<n;i++){
        cin>>dom[i].first>>dom[i].second;

        cnt[dom[i].first]++;
        cnt[dom[i].second]++;
    }

    // Check each number appears exactly twice
    bool ok=true;

    for(int i=1;i<=n;i++){
        if(cnt[i]!=2){
            ok=false;
            break;
        }
    }

    if(!ok){
        cout<<"NO"<<endl;
        return;
    }

    // Check no domino has same number twice
    for(int i=0;i<n;i++){
        if(dom[i].first==dom[i].second){
            ok=false;
            break;
        }
    }

    if(!ok){
        cout<<"NO"<<endl;
        return;
    }

    // Build graph
    for(int i=0;i<n;i++){
        adj[dom[i].first].push_back(dom[i].second);
        adj[dom[i].second].push_back(dom[i].first);
    }

    // Check bipartite
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bfsCheck(i)){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
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