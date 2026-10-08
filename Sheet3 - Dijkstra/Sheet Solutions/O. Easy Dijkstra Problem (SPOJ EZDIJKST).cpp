#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll INF = 4e18;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    int start, finish;
    cin >> start >> finish;

    vector<ll> d(n + 1, INF);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    d[start] = 0;

    pq.push({0, start});

    while (!pq.empty()) {

        auto [cost, node] = pq.top();
        pq.pop();

        if (cost != d[node])
            continue;

        if (node == finish)
            break;

        for (auto [to, w] : adj[node]) {

            if (d[to] > cost + w) {

                d[to] = cost + w;

                pq.push({d[to], to});
            }
        }
    }

    if (d[finish] == INF)
        cout << "NO" << endl;
    else
        cout << d[finish] << endl;
}

int main() {

    Fast

    int T;
    cin >> T;
    // cin.ignore();

    while (T--) {
        solve();
    }

    return 0;
}