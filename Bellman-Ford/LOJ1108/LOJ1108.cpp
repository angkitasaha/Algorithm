#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

using ll = long long;
const ll INF = numeric_limits<ll>::max() / 2;

ll calculate_cost(int source_busyness, int dest_busyness) {
    ll diff = (ll)dest_busyness - source_busyness;
    return diff * diff * diff;
}

void spfa(int start_node, int n, const vector<int>& busyness, const vector<vector<int>>& adj, vector<ll>& dist) {
    dist.assign(n + 1, INF);
    dist[start_node] = 0;

    queue<int> q;
    q.push(start_node);

    vector<bool> in_queue(n + 1, false);
    in_queue[start_node] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (int v : adj[u]) {
            ll weight = calculate_cost(busyness[u], busyness[v]);

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;

                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
}

void solve() {
    int n, test_set = 1;

    while (cin >> n) {
        if (n == 0) {
            cout << "Set #" << test_set++ << endl << endl;
            continue;
        }

        vector<int> busyness(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> busyness[i];
        }

        int r;
        cin >> r;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < r; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector<ll> min_earnings;

        spfa(1, n, busyness, adj, min_earnings);

        int q;
        cin >> q;

        cout << "Set #" << test_set++ << endl;

        for (int i = 0; i < q; ++i) {
            int dest;
            cin >> dest;

            ll earnings = min_earnings[dest];

            if (earnings == INF || earnings < 3) {
                cout << "?" << endl;
            } else {
                cout << earnings << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
