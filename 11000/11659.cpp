#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i > 0)
            v[i] += v[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > 1)
            cout << v[b - 1] - v[a - 2] << "\n";
        else
            cout << v[b - 1] << "\n";
    }

    return 0;
}
