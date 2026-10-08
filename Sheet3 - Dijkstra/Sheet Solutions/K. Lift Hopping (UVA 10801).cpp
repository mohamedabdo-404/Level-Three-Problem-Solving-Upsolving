#include <bits/stdc++.h>
#define ll long long
#define Fast ios::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
using namespace std;
#define endl '\n'

const ll INF = 4e18;

void solve(int n, int k) {

    vector<int> t(n);

    for (int i = 0; i < n; i++)
        cin >> t[i];

    string line;
    getline(cin, line);

    vector<vector<int>> floors(n);
    vector<vector<int>> has(100, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {

        getline(cin, line);

        stringstream ss(line);

        int x;

        while (ss >> x) {
            floors[i].push_back(x);
            has[x][i] = 1;
        }
    }

    // dist[elevator][floor]
    vector<vector<ll>> d(n, vector<ll>(100, INF));

    priority_queue<
        tuple<ll, int, int>,
        vector<tuple<ll, int, int>>,
        greater<tuple<ll, int, int>>
    > pq;

    // We can take any elevator from floor 0 for free
    for (int i = 0; i < n; i++) {

        if (has[0][i]) {

            d[i][0] = 0;

            pq.push({0, i, 0});
        }
    }

    while (!pq.empty()) {

        auto [cost, elevator, floor] = pq.top();
        pq.pop();

        if (cost != d[elevator][floor])
            continue;

        if (floor == k) {
            cout << cost << endl;
            return;
        }

        // Move using the same elevator
        for (int nextFloor : floors[elevator]) {

            if (nextFloor == floor)
                continue;

            ll newCost =
                cost + 1LL * abs(nextFloor - floor) * t[elevator];

            if (newCost < d[elevator][nextFloor]) {

                d[elevator][nextFloor] = newCost;

                pq.push({
                    newCost,
                    elevator,
                    nextFloor
                });
            }
        }

        // Switch elevator
        for (int nextElevator = 0; nextElevator < n; nextElevator++) {

            if (nextElevator == elevator)
                continue;

            if (!has[floor][nextElevator])
                continue;

            ll newCost = cost + 60;

            if (newCost < d[nextElevator][floor]) {

                d[nextElevator][floor] = newCost;

                pq.push({
                    newCost,
                    nextElevator,
                    floor
                });
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {

    Fast

    int n, k;

    while (cin >> n >> k) {
        solve(n, k);
    }

    return 0;
}