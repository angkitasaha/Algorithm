#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <tuple>
#include <iomanip>

using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

pair<int, int> to_coords(const string& s) {
    int col = s[0] - 'a';
    int row = s[1] - '1';
    return {row, col};
}

int bfs(const string& start_sq, const string& end_sq) {
    if (start_sq == end_sq) {
        return 0;
    }

    pair<int, int> start_coords = to_coords(start_sq);
    pair<int, int> end_coords = to_coords(end_sq);

    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int, int>> q;

    dist[start_coords.first][start_coords.second] = 0;
    q.push(start_coords);

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int r = current.first;
        int c = current.second;

        if (r == end_coords.first && c == end_coords.second) {
            return dist[r][c];
        }

        for (int i = 0; i < 8; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1;
}

void solve() {
    string a, b;
    while (cin >> a >> b) {
        int moves = bfs(a, b);
        cout << "To get from " << a << " to " << b << " takes " << moves << " knight moves." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
