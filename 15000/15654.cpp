#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int d, vector<int> &record, vector<int> &list, int m, int n) {
    if (d == m) {
        for (int i = 0; i < record.size(); i++) {
            cout << record[i] << " ";
        }
        cout << "\n";
        return;
    } else {
        for (int i = 0; i < n; i++) {
            bool isDuplicate = false;
            for (int j = 0; j < record.size(); j++) { // 이미 뽑은 숫자인지 확인
                if (record[j] == list[i]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                record.push_back(list[i]);
                dfs(d + 1, record, list, m, n);
                record.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> list(n);
    vector<int> record;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    sort(list.begin(), list.end());
    dfs(0, record, list, m, n);

    return 0;
}
