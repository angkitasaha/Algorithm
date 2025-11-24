#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
const int INF = 1e9;
using Edge = pair<int, int>;
void solve_case(int case_num) {
    int N, R;
    if (!(cin >> N >> R)) return;
    vector<Edge> adj[N + 1];
    for (int i = 0; i < R; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> d1(N + 1, INF);
    vector<int> d2(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (current_dist > d2[u]) {
            continue;
        }
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            int new_dist = current_dist + weight;
            if (new_dist < d1[v]) {
                d2[v] = d1[v];
                d1[v] = new_dist;

                pq.push({d1[v], v});
                if (d2[v] != INF) {
                    pq.push({d2[v], v});
                }
            }
            else if (new_dist > d1[v] && new_dist < d2[v]) {
                d2[v] = new_dist;


                pq.push({d2[v], v});
            }

        }
    }


    cout << "Case " << case_num << ": " << d2[N] << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        solve_case(t);
    }

    return 0;
}
