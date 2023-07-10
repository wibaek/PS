#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int numberOfStudents;
    cin >> numberOfStudents;
    vector<vector<int>> table(numberOfStudents, vector<int>(5, 0));

    vector<vector<int>> meet(numberOfStudents,
                             vector<int>(numberOfStudents, 0));
    for (int i = 0; i < numberOfStudents; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < numberOfStudents - 1; j++) {
            for (int k = j + 1; k < numberOfStudents; k++) {
                if (table[j][i] == table[k][i]) {
                    meet[j][k] = 1;
                    meet[k][j] = 1;
                }
            }
        }
    }
    int max = 0;
    int maxIndex = 0;
    int count = 0;

    for (int i = 0; i < numberOfStudents; i++) {
        count = 0;
        for (int j = 0; j < numberOfStudents; j++) {
            if (meet[i][j] == 1) {
                count++;
            }
        }
        if (max < count) {
            max = count;
            maxIndex = i;
        }
    }

    cout << maxIndex + 1 << endl;

    return 0;
}
