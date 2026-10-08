#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
using namespace std;
#define endl '\n'

vector<vector<pair<ll,ll>>> adj(100005);
vector<int> vis(100005);


vector<ll> dist(1 << 10,INT_MAX);

void dijkstra(int start){
    //dist , node
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    dist[start]=0;
    pq.push({0,start});

    while (!pq.empty())
    {
        auto [cur_dist,cur_node] = pq.top();
        pq.pop();

        if(cur_dist != dist[cur_node]){
            continue;
        }

        for(auto i:adj[cur_node]){
            if(dist[cur_node] + i.second < dist[i.first]){
                dist[i.first] = dist[cur_node] + i.second;
                pq.push({dist[i.first],i.first});
            }
        }
    }
}

void solve(){
    ll n,m;
    cin >> n >> m;

    string s;
    cin >> s;

    int start = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            start |= (1 << i);
        }
    }

    vector<ll> days(m);
    vector<int> removeMask(m),sideMask(m);

    for(int i = 0; i < m; i++){
        cin >> days[i];

        string remove,side;
        cin >> remove >> side;

        for(int j = 0; j < n; j++){
            if(remove[j] == '1'){
                removeMask[i] |= (1 << j);
            }

            if(side[j] == '1'){
                sideMask[i] |= (1 << j);
            }
        }
    }

    int states = (1 << n);

    adj.assign(states,{});
    dist.assign(states,INT_MAX);

    for(int mask = 0; mask < states; mask++){

        for(int i = 0; i < m; i++){

            int newMask = (mask & ~removeMask[i]) | sideMask[i];

            adj[mask].push_back({newMask,days[i]});
        }
    }


    dijkstra(start);

    if(dist[0] == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << dist[0] << endl;
    }
}

int main(){

    Fast

    ll T;
    cin >> T;
    // cin >> T;
    // cin.ignore();
    while(T--){
        solve();
    }
}