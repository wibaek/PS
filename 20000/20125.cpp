#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
int foundLeftArm(vector<vector<int>> &v, int x, int y) {
    if (x - 1 >= 0 && v[y][x - 1] == 1)
        return 1 + foundLeftArm(v, x - 1, y);
    else
        return 0;
}

int foundRightArm(vector<vector<int>> &v, int x, int y) {
    if (x + 1 < n && v[y][x + 1] == 1)
        return 1 + foundRightArm(v, x + 1, y);
    else
        return 0;
}

int foundLeg(vector<vector<int>> &v, int x, int y) {
    if (y + 1 < n && v[y + 1][x] == 1)
        return 1 + foundLeg(v, x, y + 1);
    else
        return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++) {
        v.push_back(vector<int>(n));
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == '_')
                v[i][j] = 0;
            else
                v[i][j] = 1;
        }
    }

    int heartX, heartY;
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) {
                heartX = j;
                heartY = i + 1;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    cout << heartY + 1 << ' ' << heartX + 1 << endl;
    cout << foundLeftArm(v, heartX, heartY) << ' '
         << foundRightArm(v, heartX, heartY) << ' ';

    int centerY = heartY;
    while (v[centerY + 1][heartX] == 1)
        centerY++;
    cout << centerY - heartY << ' ' << 1 + foundLeg(v, heartX - 1, centerY + 1)
         << ' ' << 1 + foundLeg(v, heartX + 1, centerY + 1);

    return 0;
}
