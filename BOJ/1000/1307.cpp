#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    cout << v[n - 1] * v[0];

    return 0;
}
