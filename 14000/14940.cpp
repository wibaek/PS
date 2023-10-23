#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int n, m;
    cin >> n >> m;
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            v[i][j] = -v[i][j];
            // 0: 갈 수 없는 땅, -1: 갈 수 있는 땅, -2: 목표 지점
            if (v[i][j] == -2) {
                q.push(make_pair(0, make_pair(i, j)));
                v[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int c = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;

        q.pop();
        for (int i = 0; i < 4; i++) {
            if ((x + dx[i] >= 0 && x + dx[i] < m) &&
                (y + dy[i] >= 0 && y + dy[i] < n)) {

                if (v[y + dy[i]][x + dx[i]] == -1) {
                    v[y + dy[i]][x + dx[i]] = c + 1;
                    q.push(make_pair(c + 1, make_pair(y + dy[i], x + dx[i])));
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
