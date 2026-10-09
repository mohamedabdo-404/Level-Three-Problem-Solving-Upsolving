#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

int N;
ll a[100005];
int dp[100005];       // dp[i] = best length ending at index i
int dpP[100005];      // dpP[prime] = best length of subseq ending with element having this prime

int rec(int i){
    if(dp[i]!=-1) return dp[i];
    dp[i]=1;
    // find all prime factors of a[i]
    ll x=a[i];
    vector<int>primes;
    for(ll p=2;p*p<=x;p++){
        if(x%p==0){
            primes.push_back(p);
            while(x%p==0) x/=p;
        }
    }
    if(x>1) primes.push_back(x);
    // best we can extend from any prime factor
    for(int p:primes)
        dp[i]=max(dp[i],dpP[p]+1);
    return dp[i];
}

void solve(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];

    memset(dp,-1,sizeof(dp));
    memset(dpP,0,sizeof(dpP));

    int ans=1;
    for(int i=0;i<N;i++){
        rec(i);
        ans=max(ans,dp[i]);
        // update dpP for each prime factor of a[i]
        ll x=a[i];
        for(ll p=2;p*p<=x;p++){
            if(x%p==0){
                dpP[p]=max(dpP[p],dp[i]);
                while(x%p==0) x/=p;
            }
        }
        if(x>1) dpP[x]=max(dpP[x],dp[i]);
    }
    cout<<ans<<endl;
}

int main(){
    Fast
    ll T=1;
    // cin>>T;
    while(T--) solve();
}