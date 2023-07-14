#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &table, const int t, int i, int j, const int n) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return;
    }
    if (table[i][j] == 0) {
        return;
    }
    if (table[i][j] != t) {
        return;
    }
    table[i][j] = 0;
    dfs(table, t, i - 1, j, n);
    dfs(table, t, i + 1, j, n);
    dfs(table, t, i, j - 1, n);
    dfs(table, t, i, j + 1, n);
}

void check(vector<vector<int>> &table, int &count, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] != 0) {
                count += 1;
                dfs(table, table[i][j], i, j, n);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    char ch;
    vector<vector<int>> normalTable(n, vector<int>(n, 0));
    vector<vector<int>> colorTable(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ch;
            if (ch == 'R') {
                normalTable[i][j] = 1;
                colorTable[i][j] = 1;
            } else if (ch == 'G') {
                normalTable[i][j] = 2;
                colorTable[i][j] = 1;
            } else {
                normalTable[i][j] = 3;
                colorTable[i][j] = 2;
            }
        }
    }
    int normalCount = 0;
    int colorCount = 0;

    check(normalTable, normalCount, n);
    check(colorTable, colorCount, n);

    cout << normalCount << " " << colorCount;

    return 0;
}