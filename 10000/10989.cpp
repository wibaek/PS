#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, inp;
    cin >> n;
    int v[10001] = {
        0,
    };
    for (int i = 0; i < n; i++) {
        cin >> inp;
        v[inp]++;
    }
    for (int i = 1; i <= 10000; i++) {
        if (v[i] > 0) {
            for (int j = 0; j < v[i]; j++) {
                cout << i << "\n";
            }
        }
    }

    return 0;
}
