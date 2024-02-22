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

    string s;
    cin >> s;

    int l = s.length();
    int c = 0;

    while (c < l - 1) {
        if (c == l - 1) {
            // 남은 신호가 하나인경우
            cout << "NOISE";
            return 0;
        }
        if (s[c] == '0') {
            if (s[c + 1] == '1') {
                c += 2;
            } else {
                cout << "NOISE";
                return 0;
            }
        } else if (s[c] == '1' &&) {
            if (s[c + 1] == '0' && s[c + 2] == '0') {
                c += 3;
                while (c < l - 1 && s[c] == '0')
                    c++;
                if (c == l - 1) {
                    cout << "NOISE";
                    return 0;
                }
                while ()
            }
        }
    }

    cout << "SUBMARINE";

    return 0;
}
