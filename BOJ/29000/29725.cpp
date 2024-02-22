#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v(8);
    for (int i = 0; i < 8; i++) {
        cin >> v[i];
    }

    char mem[13] = {'K', 'P', 'N', 'B', 'R', 'Q', 'k',
                    'p', 'n', 'b', 'r', 'q', '.'};
    int score[13] = {0, 1, 3, 3, 5, 9, 0, -1, -3, -3, -5, -9, 0};

    int answer{0};
    for (string s : v) {
        for (char c : s) {
            for (int i = 0; i < 13; i++) {
                if (c == mem[i]) {
                    answer += score[i];
                    break;
                }
            }
        }
    }

    cout << answer;

    return 0;
}
