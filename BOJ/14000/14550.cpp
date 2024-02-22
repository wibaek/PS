#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int n, s, t;
        cin >> n;
        if (n == 0)
            return 0;

        cin >> s >> t;

        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        v.push_back(0);

        vector<int> dp1(n + 2, -1234567890);
        vector<int> dp2(n + 2, -1234567890);
        dp1[0] = 0;
        for (int k = 0; k < t; k++) {
            for (int i = 0; i < n + 2; i++) {
                dp2[i] = dp1[i];
            }
            for (int i = 0; i <= n + 1; i++) {
                for (int j = 1; j <= s; j++) {
                    if (i + j >= n + 2)
                        break;
                    dp1[i + j] = max(dp1[i + j], dp2[i] + v[i + j]);
                }
            }
        }

        cout << dp1[n + 1] << "\n";
    }

    return 0;
}
