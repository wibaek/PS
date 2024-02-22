#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    while (n >= 10) {
        v.push_back(n % 10);
        n /= 10;
    }
    v.push_back(n);
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }

    return 0;
}
