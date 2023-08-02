#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, h;
    cin >> m >> n >> h;

    int box[100][100][100];
    queue<pair<int, pair<int, int>>> q;
    int day = 0;

    // 값 입력
    int unRipen = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 0) {
                    unRipen++;
                }
            }
        }
    }
    q.push(make_pair(-1, make_pair(-1, -1)));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (box[i][j][k] == 1) {
                    if (i - 1 >= 0 && box[i - 1][j][k] == 0) {
                        q.push(make_pair(i - 1, make_pair(j, k)));
                    }
                    if (i + 1 < h && box[i + 1][j][k] == 0) {
                        q.push(make_pair(i + 1, make_pair(j, k)));
                    }
                    if (j - 1 >= 0 && box[i][j - 1][k] == 0) {
                        q.push(make_pair(i, make_pair(j - 1, k)));
                    }
                    if (j + 1 < n && box[i][j + 1][k] == 0) {
                        q.push(make_pair(i, make_pair(j + 1, k)));
                    }
                    if (k - 1 >= 0 && box[i][j][k - 1] == 0) {
                        q.push(make_pair(i, make_pair(j, k - 1)));
                    }
                    if (k + 1 < m && box[i][j][k + 1] == 0) {
                        q.push(make_pair(i, make_pair(j, k + 1)));
                    }
                }
            }
        }
    }
    q.push(make_pair(-1, make_pair(-1, -1)));
    int i, j, k;
    while (true) {
        if (q.size() == 2 || unRipen == 0) {
            break;
        }
        q.pop();
        while (q.front().first != -1) {
            i = q.front().first;
            j = q.front().second.first;
            k = q.front().second.second;
            if (box[i][j][k] == 1) {
                q.pop();
                continue;
            }
            box[i][j][k] = 1;
            unRipen--;
            if (i - 1 >= 0 && box[i - 1][j][k] == 0) {
                q.push(make_pair(i - 1, make_pair(j, k)));
            }
            if (i + 1 < h && box[i + 1][j][k] == 0) {
                q.push(make_pair(i + 1, make_pair(j, k)));
            }
            if (j - 1 >= 0 && box[i][j - 1][k] == 0) {
                q.push(make_pair(i, make_pair(j - 1, k)));
            }
            if (j + 1 < n && box[i][j + 1][k] == 0) {
                q.push(make_pair(i, make_pair(j + 1, k)));
            }
            if (k - 1 >= 0 && box[i][j][k - 1] == 0) {
                q.push(make_pair(i, make_pair(j, k - 1)));
            }
            if (k + 1 < m && box[i][j][k + 1] == 0) {
                q.push(make_pair(i, make_pair(j, k + 1)));
            }

            q.pop();
        }
        day++;
        q.push(make_pair(-1, make_pair(-1, -1)));
    }

    if (unRipen == 0) {
        cout << day << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
