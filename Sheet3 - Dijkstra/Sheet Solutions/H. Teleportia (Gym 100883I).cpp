#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll INF = 4e18;

struct Point {
    ll x, y, p;
};

ll walk(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

ll dist2(Point a, Point b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;

    return dx * dx + dy * dy;
}

void solve() {

    int n;
    cin >> n;

    vector<Point> points(n + 2);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].p;
    }

    cin >> points[n].x >> points[n].y;
    cin >> points[n + 1].x >> points[n + 1].y;

    int start = n;
    int finish = n + 1;

    vector<vector<pair<int, ll>>> adj(n + 2);

    // Walking
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {

            ll cost = walk(points[i], points[j]);

            adj[i].push_back({j, cost});
            adj[j].push_back({i, cost});
        }
    }

    // Teleportation
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (i == j)
                continue;

            if (dist2(points[i], points[j]) <= points[i].p * points[i].p) {
                adj[i].push_back({j, 2});
            }
        }
    }

    // Dijkstra
    vector<ll> d(n + 2, INF);

    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>> pq;

    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {

        auto [cost, node] = pq.top();
        pq.pop();

        if (cost != d[node])
            continue;

        for (auto [to, w] : adj[node]) {

            if (d[to] > cost + w) {

                d[to] = cost + w;

                pq.push({d[to], to});
            }
        }
    }

    cout << d[finish] << endl;
}

int main() {

    Fast

    int T = 1;
    cin >> T;
    // cin.ignore();

    while (T--) {
        solve();
    }

    return 0;
}