#include <iostream>
using namespace std;

void star(int n, int x, int y, int **arr) {
    if (n == 3) {
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                arr[i][j] = 1;
            }
        }
        arr[x + 1][y + 1] = 0;
    } else {
        star(n / 3, x, y, arr);
        star(n / 3, x, y + n / 3, arr);
        star(n / 3, x, y + n / 3 * 2, arr);
        star(n / 3, x + n / 3, y, arr);
        star(n / 3, x + n / 3, y + n / 3 * 2, arr);
        star(n / 3, x + n / 3 * 2, y, arr);
        star(n / 3, x + n / 3 * 2, y + n / 3, arr);
        star(n / 3, x + n / 3 * 2, y + n / 3 * 2, arr);
    }
}

int main() {
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n]{
            0,
        };
    }
    star(n, 0, 0, arr);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
