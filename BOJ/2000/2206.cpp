#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[1001][1001];    // 지도 데이터
int dis[1001][1001][2]; // 최소 경로 길이

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 선언
    int n, m, x, y, isBreak;
    pair<pair<int, int>, int> data;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string str;
    const int INF = 987654321;

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            dis[i][j][0] = INF;
            dis[i][j][1] = INF;
        }
    }

    // 입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    // BFS
    queue<pair<pair<int, int>, int>> q;
    dis[0][0][0] = 0;
    q.push({{0, 0}, 0});

    while (!q.empty() &&
           (dis[n - 1][m - 1][0] == INF && dis[n - 1][m - 1][1] == INF)) {
        data = q.front();
        q.pop();
        y = data.first.first;
        x = data.first.second;
        isBreak = data.second;

        for (int i = 0; i < 4; i++) {
            if (x + dx[i] >= 0 && x + dx[i] < m && y + dy[i] >= 0 &&
                y + dy[i] < n) {
                if (isBreak == 0) {
                    if (map[y + dy[i]][x + dx[i]] == 0 &&
                        dis[y + dy[i]][x + dx[i]][0] == INF) {
                        dis[y + dy[i]][x + dx[i]][0] = dis[y][x][0] + 1;
                        q.push({{y + dy[i], x + dx[i]}, 0});
                    } else if (map[y + dy[i]][x + dx[i]] == 1 &&
                               dis[y + dy[i]][x + dx[i]][1] == INF) {
                        dis[y + dy[i]][x + dx[i]][1] = dis[y][x][0] + 1;
                        q.push({{y + dy[i], x + dx[i]}, 1});
                    }

                } else if (isBreak == 1) {
                    if (map[y + dy[i]][x + dx[i]] == 0 &&
                        dis[y + dy[i]][x + dx[i]][1] == INF) {
                        dis[y + dy[i]][x + dx[i]][1] = dis[y][x][1] + 1;
                        q.push({{y + dy[i], x + dx[i]}, 1});
                    }
                }
            }
        }
    }

    if (dis[n - 1][m - 1][0] == INF && dis[n - 1][m - 1][1] == INF) {
        cout << -1;
    } else {
        cout << min(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]) + 1;
    }

    return 0;
}
