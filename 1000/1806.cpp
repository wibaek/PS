#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, temp;
    cin >> n >> s;
    vector<int> seq;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        seq.push_back(temp);
    }

    int answer = 100001;
    int currentSum = seq[0];
    int j = 1;
    // seq[i] 부터 seq[j-1]까지의 값
    for (int i = 0; i < n; i++) {
        while (currentSum < s && j < n) {
            currentSum += seq[j++];
        }
        if (currentSum >= s) {
            if (j - i < answer) {
                answer = j - i;
            }
        }

        currentSum -= seq[i];
    }

    if (answer == 100001)
        cout << 0;
    else
        cout << answer;
    return 0;
}
