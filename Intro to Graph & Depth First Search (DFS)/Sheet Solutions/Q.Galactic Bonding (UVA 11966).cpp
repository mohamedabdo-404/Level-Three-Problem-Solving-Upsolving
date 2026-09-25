#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

struct Point{
    double x,y;
};

vector<Point>stars;
vector<int>vis;

double D;

double dist(Point a,Point b){

    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

void dfs(int node){//O(n^2)

    vis[node] = 1;

    for(int i = 0; i < stars.size(); i++){

        if(!vis[i] && dist(stars[node],stars[i]) <= D){
            dfs(i);
        }
    }
}

void solve(){

    ll n;
    cin>>n>>D;

    stars.clear();
    vis.assign(n,0);

    for(int i = 0; i < n; i++){

        double x,y;
        cin>>x>>y;

        stars.push_back({x,y});
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){

        if(!vis[i]){

            ans++;

            dfs(i);
        }
    }

    cout<<ans<<endl;
}

int main(){

    Fast

    ll T;
    cin>>T;

    for(int tc = 1; tc <= T; tc++){

        cout<<"Case "<<tc<<": ";

        solve();
    }
}