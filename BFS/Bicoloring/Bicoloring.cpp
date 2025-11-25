#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int l;
        cin >> l;

        vector<vector<int>> adj(n);
        for (int i = 0; i < l; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, 0);
        queue<int> q;
        bool is_bicolorable = true;

        int start_node = 0;
        color[start_node] = 1;
        q.push(start_node);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int next_color = 3 - color[u];

            for (int v : adj[u]) {
                if (color[v] == 0) {
                    color[v] = next_color;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    is_bicolorable = false;
                    break;
                }
            }
            if (!is_bicolorable) break;
        }

        if (is_bicolorable) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }

    return 0;
}
