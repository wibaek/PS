#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // 0: 미방문, -1: 팀을 이룸, n>0: n번째에서 시작했을때 도달 가능.
    vector<int> status(n + 1);
    // 이거 약간 생각해보니 그래프 순환문제 같기도?
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (status[cur] != -1) {
            if (status[cur] == i) {
                while (status[cur] != -1) {
                    status[cur] = -1;
                    cur = v[cur];
                }
                break;
            }
            if (status[cur] > 1)
                break;
            status[cur] = i;
            cur = v[cur];
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (status[i] != -1)
            answer++;
    }
    cout << answer << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }

    return 0;
}
