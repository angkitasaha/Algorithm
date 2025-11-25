#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int bfs(int start, int end, const vector<vector<int>>& adj) {
    vector<int> distance(21, -1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end) {
            return distance[u];
        }

        for (int v : adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    return -1;
}

void solve() {
    int testSet = 1;

    while (cin.peek() != EOF) {
        vector<vector<int>> adj(21);

        for (int i = 1; i <= 19; ++i) {
            int x;
            if (!(cin >> x)) return;

            for (int k = 0; k < x; ++k) {
                int j;
                cin >> j;

                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }

        int n;
        if (!(cin >> n)) return;

        cout << setw(10) << "" << "Test Set #" << testSet++ << endl;

        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;

            int minConquests = bfs(a, b, adj);

            cout << right << setw(2) << a;
            cout << " to ";
            cout << right << setw(2) << b;
            cout << ": ";
            cout << left << setw(2) << minConquests << endl;
        }

        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
