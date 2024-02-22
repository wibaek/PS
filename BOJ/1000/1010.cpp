#include <iostream>

using namespace std;

int main() {
    int DP[31][31];
    for (int i = 0; i < 31; i++) {
        DP[i][0] = 1;
        DP[i][i] = 1;
    }
    for (int i = 2; i < 31; i++) {
        for (int j = 1; j < i; j++) {
            DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
        }
    }

    int count, n, r;
    cin >> count;
    while (count--) {
        cin >> r >> n;
        // get nCr n! / r! * (n - r)!
        cout << DP[n][r] << "\n";
    }

    return 0;
}
