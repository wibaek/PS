#include <algorithm>
#include <iostream>
using namespace std;

int d[101][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            d[i][j] = 123456789;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    // floyd-warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k)
                continue;
            for (int j = 1; j <= n; j++) {
                if (i == j || j == k)
                    continue;
                if (d[i][k] && d[k][j]) {
                    if (d[i][j] == 0)
                        d[i][j] = d[i][k] + d[k][j];
                    else
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] >= 123456789 || i == j)
                cout << 0 << " ";
            else
                cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}