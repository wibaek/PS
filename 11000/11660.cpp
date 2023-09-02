#include <algorithm>
#include <iostream>
using namespace std;

int t[1025][1025];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a, b, c, d, ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
            if (j != 0) {
                t[i][j] += t[i][j - 1];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        ans = 0;
        for (int j = a - 1; j <= c - 1; j++) {
            ans += t[j][d - 1];
            if (b != 1) {
                ans -= t[j][b - 2];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
