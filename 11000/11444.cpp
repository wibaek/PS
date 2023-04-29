#include <iostream>
#include <vector>
using namespace std;
long long n;

vector<vector<long long>> times(vector<vector<long long>> &a,
                                vector<vector<long long>> &b) {
    vector<vector<long long>> c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];

            c[i][j] %= 1000000007;
        }
    return c;
}

int main() {
    cin >> n;
    vector<vector<long long>> ans = {{1, 0}, {0, 1}};
    vector<vector<long long>> a = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n % 2 == 1) {
            ans = times(ans, a);
            n--;
        }
        a = times(a, a);
        n /= 2;
    }

    cout << ans[0][1] % 1000000007;
}