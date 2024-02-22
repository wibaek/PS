#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int a;
    vector<pair<int, int>> v;
    for (int i = 0; i < 8; i++) {
        cin >> a;
        v.push_back(make_pair(a, i + 1));
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int sum = 0;
    vector<int> idx;
    for (int i = 0; i < 5; i++) {
        sum += v[i].first;
        idx.push_back(v[i].second);
    }
    sort(idx.begin(), idx.end());

    cout << sum << endl;
    for (int i = 0; i < 5; i++) {
        cout << idx[i] << " ";
    }

    return 0;
}
