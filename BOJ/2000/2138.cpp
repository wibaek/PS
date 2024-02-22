#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void change(vector<bool> &v, int i) {
    if (i == 0) {
        v[0] = !v[0];
        v[1] = !v[1];
    } else if (i == v.size() - 1) {
        v[i] = !v[i];
        v[i - 1] = !v[i - 1];
    } else {
        v[i - 1] = !v[i - 1];
        v[i] = !v[i];
        v[i + 1] = !v[i + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<bool> need_change(n);

    string current, goal;
    cin >> current;
    cin >> goal;

    for (int i = 0; i < n; i++) {
        if (current[i] == goal[i])
            need_change[i] = false;
        else
            need_change[i] = true;
    }

    vector<bool> need_change2(n);
    for (int i = 0; i < n; i++) {
        need_change2[i] = need_change[i];
    }
    int answer{0};

    // 목표는 모두 0이 되는 것

    // [0]에서 바꾸기 미실행
    for (int i = 1; i < n; i++) {
        if (need_change[i - 1] == 1) {
            change(need_change, i);
            answer++;
        }
    }
    if (need_change[n - 1] == 0) {
        cout << answer;
        return 0;
    }

    // [0]에서 바꾸기 실행
    answer = 1;
    change(need_change2, 0);
    for (int i = 1; i < n; i++) {
        if (need_change2[i - 1] == 1) {
            change(need_change2, i);
            answer++;
        }
    }
    if (need_change2[n - 1] == 0) {
        cout << answer;
        return 0;
    }
    cout << -1;

    return 0;
}
