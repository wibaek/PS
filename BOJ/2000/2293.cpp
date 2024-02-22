#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, objective;
    cin >> n >> objective;
    vector<int> v(n);
    vector<long long int> dp(objective + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= objective; j++) {
            if (j - v[i] >= 0)
                dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[objective];
    return 0;
}
