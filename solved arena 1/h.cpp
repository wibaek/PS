#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int n, m, q;
    // cin >> n >> m >> q;

    // int a, b, c;
    // for (int i = 0; i < q; i++) {
    //     cin >> a >> b >> c;
    //     if (a == 1) {
    //         for (int j = 0; j < m; j++) {
    //             v[b - 1][j] += c;
    //         }
    //     } else {
    //         for (int j = 0; j < n; j++) {
    //             v[j][b - 1] += c;
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    int d, r, v;
    for (int i = 0; i < q; i++) {
        cin >> d >> r >> v;
        if (d == 1) {
            row[r - 1] += v;
        } else {
            col[r - 1] += v;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << row[i] + col[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
