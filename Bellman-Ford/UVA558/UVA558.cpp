#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, t;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        edges.push_back({u, v, t});
    }

    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (const auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.t < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.t;
                updated = true;
            }
        }

        if (!updated) break;
    }


    bool possible = false;
    for (const auto& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.t < dist[edge.v]) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "possible" << endl;
    } else {
        cout << "not possible" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    if (!(cin >> c)) return 0;

    while (c--) {
        solve();
    }

    return 0;
}
