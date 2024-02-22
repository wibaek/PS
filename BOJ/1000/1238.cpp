#include <algorithm>
#include <iostream>
using namespace std;

int d[1001][1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 학생 1000명
    // 도로 10000개
    // 각 학생이 X로 갈때는 각 학생별로 다익스트라가 필요하지만
    // X에서 각 학생으로 가는건 X기준으로 완전탐색 한번만 해도 될듯?
    // 일단 플로이드 워셜로
    int n, m, x, a, b, c;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        d[a][b] = c;
    }

    // floyd-warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k)
                continue;
            for (int j = 1; j <= n; j++) {
                if (i == j || j == k)
                    continue;
                if (d[i][k] && d[k][j]) {
                    if (d[i][j] == 0)
                        d[i][j] = d[i][k] + d[k][j];
                    else
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x)
            continue;
        ans = max(ans, d[i][x] + d[x][i]);
    }
    cout << ans;

    return 0;
}