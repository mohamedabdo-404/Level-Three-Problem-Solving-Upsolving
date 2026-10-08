#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<int>>adj(26);
vector<int>indegree(26,0);

void solve(){
    int n;
    cin>>n;

    vector<string>names(n);
    for(int i=0;i<n;i++) cin>>names[i];

    bool impossible=false;

    for(int i=0;i<n-1;i++){
        string&a=names[i];
        string&b=names[i+1];
        int len=min(a.size(),b.size());
        bool found=false;
        for(int j=0;j<(int)len;j++){
            if(a[j]!=b[j]){
                int u=a[j]-'a',v=b[j]-'a';
                adj[u].push_back(v);
                indegree[v]++;
                found=true;
                break;
            }
        }
        // If a is prefix of b and a is longer => impossible
        if(!found && a.size()>b.size()){
            impossible=true;
        }
    }

    if(impossible){
        cout<<"Impossible"<<endl;
        return;
    }

    // Kahn's topological sort
    queue<int>q;
    for(int i=0;i<26;i++){
        if(indegree[i]==0) q.push(i);
    }

    string result="";
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        result+=(char)('a'+cur);

        for(auto i:adj[cur]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }

    if((int)result.size()<26){
        cout<<"Impossible"<<endl;
    }else{
        cout<<result<<endl;
    }
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
