#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll INF = 4e18;

struct Edge {
    int to, w;
};

int n, m;
ll T;

vector<vector<Edge>> adj;

bool check(int x) {

    vector<ll> d(n + 1, INF);

    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>> pq;

    d[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {

        auto [cost, node] = pq.top();
        pq.pop();

        if (cost != d[node])
            continue;

        if (cost > T)
            continue;

        if (node == n)
            return true;

        for (auto [to, w] : adj[node]) {

            if (w < x)
                continue;

            if (cost + w > T)
                continue;

            if (d[to] > cost + w) {

                d[to] = cost + w;

                pq.push({d[to], to});
            }
        }
    }

    return false;
}

void solve() {

    cin >> n >> m >> T;

    adj.assign(n + 1, {});

    int mx = 0;

    for (int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        mx = max(mx, w);
    }

    int l = 1, r = mx;
    int ans = -1;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (check(mid)) {

            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    if (ans == -1)
        cout << "He is taking an uber." << endl;
    else
        cout << ans << endl;
}

int main() {

    Fast
    int T = 1;
    // cin >> T;
    // cin.ignore();

    while (T--) {
        solve();
    }
    return 0;
}