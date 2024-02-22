#include <iostream>
using namespace std;

int main() {
    int count, x, y;
    cin >> count;
    int table[100][100];
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            table[i][j] = 0;
        }
    }
    while (count--) {
        cin >> x >> y;
        for (int i = y; i < y + 10; ++i) {
            for (int j = x; j < x + 10; ++j) {
                table[i][j] = 1;
            }
        }
    }

    int ans{0};
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            ans += table[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
