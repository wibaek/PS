#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(bool table[][1001], vector<bool> &record, int k, const int n) {
    cout << k << " ";
    record[k] = true;
    for (int i = 1; i <= n; i++) {
        if (table[k][i] && !record[i]) {
            dfs(table, record, i, n);
        }
    }
}

void bfs(bool table[][1001], vector<bool> &record, int k, const int n) {
    queue<int> q;
    q.push(k);
    record[k] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for (int i = 1; i <= n; i++) {
            if (table[t][i] && !record[i]) {
                q.push(i);
                record[i] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool table[1001][1001] = {false};

    int n, m, v;
    cin >> n >> m >> v;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        table[a][b] = true;
        table[b][a] = true;
    }
    vector<bool> dfsRecord(n + 1, false);
    vector<bool> bfsRecord(n + 1, false);

    dfs(table, dfsRecord, v, n);
    cout << endl;
    bfs(table, bfsRecord, v, n);

    return 0;
}
