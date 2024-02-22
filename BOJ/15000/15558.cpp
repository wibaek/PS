#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    // input
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> safe(2);
    vector<vector<bool>> mem(2, vector<bool>(n, 0));
    string s;
    for (int i = 0; i <= 1; i++) {
        cin >> s;
        for (char c : s) {
            if (c == '0')
                safe[i].push_back(false);
            else
                safe[i].push_back(true);
        }
    }

    // solution
    queue<pair<int, int>> q; // map, idx, (-1, n) 이면 n번째 턴 끝
    int turn{0};
    q.push(make_pair(0, 0));
    q.push(make_pair(-1, turn));

    while (!q.empty() && turn <= n) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (a != -1) {
            if (mem[a][b])
                continue;
            mem[a][b] = true;
            if (b > n - 1) {
                cout << 1;
                return 0;
            }
        }
        if (a == -1) {
            turn++;
            q.push(make_pair(-1, turn));
        } else {
            if (b < turn)
                continue;
            if (b + k > n - 1) {
                cout << 1;
                return 0;
            }
            int other = (a == 0) ? 1 : 0;

            if (safe[a][b - 1] && (b - 1 > turn))
                q.push(make_pair(a, b - 1));
            if (safe[a][b + 1] && (b + 1 > turn))
                q.push(make_pair(a, b + 1));
            if (safe[other][b + k] && (b + k > turn))
                q.push(make_pair(other, b + k));
        }
    }
    cout << 0;

    return 0;
}
