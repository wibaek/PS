#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

void bfs(vector<vector<int>> &v, int y_init, int x_init, const int n,
         const int m) {
    queue<pair<int, int>> q;
    q.push(make_pair(y_init, x_init));
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (v[y][x] == 0) {
            v[y][x] = 1;
            if (v[(y == 0) ? (n - 1) : (y - 1)][x] == 0)
                q.push(make_pair((y == 0) ? (n - 1) : (y - 1), x));
            if (v[y][(x == 0) ? (m - 1) : (x - 1)] == 0)
                q.push(make_pair(y, (x == 0) ? (m - 1) : (x - 1)));
            if (v[(y == n - 1) ? 0 : (y + 1)][x] == 0)
                q.push(make_pair((y == n - 1) ? 0 : (y + 1), x));
            if (v[y][(x == m - 1) ? 0 : (x + 1)] == 0)
                q.push(make_pair(y, (x == m - 1) ? 0 : (x + 1)));
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    int answer{0};
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                bfs(v, i, j, n, m);
                answer++;
            }
        }
    }
    cout << answer;

    return 0;
}
