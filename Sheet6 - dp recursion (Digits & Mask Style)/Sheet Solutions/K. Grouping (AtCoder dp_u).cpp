#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int N;
ll score[16][16];
ll groupScore[1<<16];
ll dp[1<<16];
bool vis[1<<16];

ll rec(int mask){
    if(mask==0) return 0;
    if(vis[mask]) return dp[mask];
    vis[mask]=true;
    ll &ret=dp[mask];
    ret=-1e18;
    // fix lowest set bit rabbit, try all submasks containing it
    int lowest=mask&(-mask); // lowest set bit
    for(int sub=mask;sub>0;sub=(sub-1)&mask){
        if(!(sub&lowest)) continue; // must contain lowest rabbit
        ret=max(ret,groupScore[sub]+rec(mask^sub));
        if(sub==0) break;
    }
    return ret;
}
void Sol(){
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>score[i][j];
    // precompute group scores
    for(int mask=0;mask<(1<<N);mask++){
        groupScore[mask]=0;
        vector<int>members;
        for(int i=0;i<N;i++) if(mask&(1<<i)) members.push_back(i);
        for(int i=0;i<(int)members.size();i++)
            for(int j=i+1;j<(int)members.size();j++)
                groupScore[mask]+=score[members[i]][members[j]];
    }
    memset(vis,false,sizeof(vis));
    cout<<rec((1<<N)-1)<<endl;
}
int main(){
    Fast
    ll T=1;
    // cin>>T;
    // cin.ignore();
    while(T--){
        Sol();
    }
}
