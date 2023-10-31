#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, q;
    cin >> n >> q;

    vector<long long> tree(n);
    vector<long long> tree_sum(n);
    for (long long i = 0; i < n; i++) {
        cin >> tree[i];
    }
    sort(tree.begin(), tree.end());
    tree_sum[0] = tree[0];
    for (long long i = 1; i < n; i++) {
        tree_sum[i] = tree_sum[i - 1] + tree[i];
    }

    long long idx;
    while (q--) {
        cin >> idx;
        // idx 왼쪽에 있는 나무들의 거리합 = idx * 왼쪽 나무의 개수(나무가 다
        // 0에 있을때 가정한 최대값) - 각 나무의 위치 합
        // idx 오른쪽에 있는 나무들의 거리합 = 오른쪽 나무의 위치 합 - 오른쪽
        // 나무의 개수 * idx
        long long left_tree_count =
            lower_bound(tree.begin(), tree.end(), idx) - tree.begin();

        long long left_sum = 0;
        if (left_tree_count > 0)
            left_sum = idx * left_tree_count - tree_sum[left_tree_count - 1];

        long long right_sum = tree_sum[n - 1] - n * idx;
        if (left_tree_count > 0)
            right_sum = tree_sum[n - 1] - tree_sum[left_tree_count - 1] -
                        (n - left_tree_count) * idx;

        cout << left_sum + right_sum << "\n";
    }

    return 0;
}
