#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    // Build forward and reverse graphs
    vector<vector<int>>radj(n+1); // reverse adj

    for(int i=1;i<=n;i++){
        if(i+a[i]<=n){
            radj[i+a[i]].push_back(i); // i -> i+a[i], reverse: i+a[i] -> i
        }
        if(i-a[i]>=1){
            radj[i-a[i]].push_back(i); // i -> i-a[i], reverse: i-a[i] -> i
        }
    }

    // For each parity (0=even, 1=odd), do multi-source BFS on reverse graph
    // Source: nodes that have a neighbor of opposite parity (dist=1)
    vector<int>ans(n+1,-1);

    // Process even parity nodes: find min dist to odd
    // Process odd parity nodes: find min dist to even
    for(int par=0;par<=1;par++){
        vector<int>dist(n+1,-1);
        queue<int>q;

        // Sources: nodes with parity 'par' that have a direct neighbor with parity 1-par
        for(int i=1;i<=n;i++){
            if(a[i]%2!=par) continue; // only nodes of parity 'par'
            // Check forward neighbors
            int j1=i+a[i],j2=i-a[i];
            bool found=false;
            if(j1>=1&&j1<=n&&a[j1]%2==(1-par)) found=true;
            if(j2>=1&&j2<=n&&a[j2]%2==(1-par)) found=true;
            if(found){
                dist[i]=1;
                q.push(i);
            }
        }

        // BFS on reverse graph for parity 'par' nodes only
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(auto prev:radj[cur]){
                if(a[prev]%2==par && dist[prev]==-1){
                    dist[prev]=dist[cur]+1;
                    q.push(prev);
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(a[i]%2==par) ans[i]=dist[i];
        }
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
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
