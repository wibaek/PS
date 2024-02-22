#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;

void rotate(vector<int> &w, int direction) {
    if (direction == 1) {
        // clock
        int temp = w[7];
        for (int i = 6; i >= 0; i--)
            w[i + 1] = w[i];
        w[0] = temp;

    } else if (direction == -1) {
        // reverse clock
        int temp = w[0];
        for (int i = 1; i < 8; i++)
            w[i - 1] = w[i];
        w[7] = temp;
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<vector<int>> wheel(4); // N = 0, S = 1

    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        for (char c : str) {
            wheel[i].push_back(c - '0'); // 오른쪽 [2], 왼쪽 [6]
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int n, d;
        cin >> n >> d; // d = 1 clock, d = -1 reverse
        n--;
        if (n == 0) {
            if (wheel[0][2] != wheel[1][6]) {
                if (wheel[1][2] != wheel[2][6]) {
                    if (wheel[2][2] != wheel[3][6]) {
                        rotate(wheel[3], -d);
                    }
                    rotate(wheel[2], d);
                }
                rotate(wheel[1], -d);
            }
            rotate(wheel[0], d);
        } else if (n == 1) {
            if (wheel[1][6] != wheel[0][2]) {
                rotate(wheel[0], -d);
            }
            if (wheel[1][2] != wheel[2][6]) {
                if (wheel[2][2] != wheel[3][6]) {
                    rotate(wheel[3], d);
                }
                rotate(wheel[2], -d);
            }
            rotate(wheel[1], d);
        } else if (n == 2) {
            if (wheel[2][6] != wheel[1][2]) {
                if (wheel[1][6] != wheel[0][2]) {
                    rotate(wheel[0], d);
                }
                rotate(wheel[1], -d);
            }
            if (wheel[2][2] != wheel[3][6]) {
                rotate(wheel[3], -d);
            }
            rotate(wheel[2], d);

        } else if (n == 3) {
            if (wheel[3][6] != wheel[2][2]) {
                if (wheel[2][6] != wheel[1][2]) {
                    if (wheel[1][6] != wheel[0][2]) {
                        rotate(wheel[0], -d);
                    }
                    rotate(wheel[1], d);
                }
                rotate(wheel[2], -d);
            }
            rotate(wheel[3], d);
        }
    }

    cout << wheel[0][0] + wheel[1][0] * 2 + wheel[2][0] * 4 + wheel[3][0] * 8;

    return 0;
}
