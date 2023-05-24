#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// int binarySearch(const vector<int> &arr, int x) {
//     int left = 0;
//     int right = arr.size() - 1;
//     int result = -1;

//     while (left <= right) {
//         int mid = left + ((right - left) / 2);
//         if (arr[mid] * x <= k) {
//             result = mid;
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
//     return result;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h, n, m;
    long long int k;
    cin >> w >> h >> k; // 가로 길이, 세로 길이, 부원이 최대로 먹을 수 있는 크기

    cin >> n; // 가로 방향 커팅의 횟수, 즉 세로 조각의 개수는 n+1
    vector<long long int> y_cutting(n + 2);
    y_cutting[0] = 0;
    for (int i = 1; i < n + 1; i++)
        cin >> y_cutting[i];
    y_cutting[n + 1] = h;

    cin >> m; // 세로 방향 커팅의 횟수, 즉 가로 조각의 개수는 m+1
    vector<long long int> x_cutting(m + 2);
    x_cutting[0] = 0;
    for (int i = 1; i < m + 1; i++)
        cin >> x_cutting[i];
    x_cutting[m + 1] = w;

    vector<long long int> x_piece; // x방향의 피자의 각 크기
    vector<long long int> y_piece; // y방향의 피자의 각 크기
    for (int i = 0; i < m + 1; i++)
        x_piece.push_back(x_cutting[i + 1] - x_cutting[i]);

    for (int i = 0; i < n + 1; i++)

        y_piece.push_back(y_cutting[i + 1] - y_cutting[i]);

    sort(x_piece.begin(), x_piece.end());
    sort(y_piece.begin(), y_piece.end());

    long long int total = 0;

    int cur_y = n;
    for (int cur_x = 0; cur_x < m + 1; cur_x++) {
        while (cur_y > -1 && x_piece[cur_x] * y_piece[cur_y] > k)
            cur_y--;
        total += cur_y + 1;
    }

    // for (int i = 0; i < x_piece.size(); i++) {
    //     total += binarySearch(y_piece, x_piece[i]) + 1;
    // }

    cout << total;
    return 0;
}
