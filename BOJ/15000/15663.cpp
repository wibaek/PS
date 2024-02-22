#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void pick(vector<int> &v, vector<int> &path, const int n, const int m,
          vector<int> &mem) {
    if (path.size() == m) {
        for (int i = 0; i < path.size(); i++) {
            cout << v[path[i]] << " ";
        }
        cout << endl;
        return;
    }
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (find(path.begin(), path.end(), i) == path.end()) {
            if (v[i] == res) {
                continue;
            }
            res = v[i];
            path.push_back(i);
            pick(v, path, n, m, mem);
            path.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    vector<int> mem;

    int res = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == res) {
            continue;
        }
        res = v[i];
        vector<int> path;
        path.push_back(i);
        pick(v, path, n, m, mem);
    }
    return 0;
}