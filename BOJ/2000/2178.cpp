#include <iostream>
#include <queue>
#include <string>
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
    vector<vector<int>> table(n);

    string inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        for (char c : inp) {
            table[i].push_back(c - '0');
        }
    }

    queue<pair<int, int>> q; // y, x
    q.push(make_pair(0, 0));

    int counter = 2;
    q.push(make_pair(-1, -1));

    while (true) {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first == n - 1 && p.second == m - 1) {
            // n, m에 도착
            cout << counter - 1 << endl;
            break;
        }
        if (p.first == -1 && p.second == -1) {
            // bfs 한 레이어를 돌았을떄
            counter++;
            q.push(make_pair(-1, -1));
            continue;
        }
        if (table[p.first][p.second] == 1) {
            table[p.first][p.second] = counter;
            for (int i = 0; i < 4; i++) {
                if ((p.first + dy[i] >= 0 && p.first + dy[i] < n) &&
                    (p.second + dx[i] >= 0 && p.second + dx[i] < m)) {
                    q.push(make_pair(p.first + dy[i], p.second + dx[i]));
                }
            }
        }
    }

    return 0;
}
