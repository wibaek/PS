#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> v0 = {0, 1};
    vector<long long int> v1 = {1, 0};
    for (int i = 2; i < n; i++) {
        v0.push_back(v0[i - 1] + v1[i - 1]);
        v1.push_back(v0[i - 1]);
    }
    cout << v0[n - 1] + v1[n - 1];
    return 0;
}
