#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int DIV = 1000000000;
    cin >> n;

    vector<long long int> dp = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<long long int> temp = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                temp[1] += dp[0];
            } else if (j == 9) {
                temp[8] += dp[9];
            } else {
                temp[j - 1] += dp[j];
                temp[j + 1] += dp[j];
            }
        }
        for (int j = 0; j < 10; j++) {
            dp[j] = temp[j] % DIV;
            temp[j] = 0;
        }
    }

    long long int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dp[i];
        sum %= DIV;
    }
    cout << sum;
    return 0;
}
