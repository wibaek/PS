/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and
       afterward, the program will read from input.txt file instead of
       standard(keyboard) input. To test your program, you may save input data
       in input.txt file, and use freopen function to read from the file when
       using cin function. You may remove the comment symbols(//) in the below
       statement and use it. Use #include<cstdio> or #include <stdio.h> to use
       the function in your program. But before submission, you must remove the
       freopen function or rewrite comment symbols(//).
     */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {

        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
         */
        // 테케 55, r, p <= 25만, 다 합쳐서 300만 아래
        // 아.. 동적 계획법으로 [i]까지의 가장 효율좋은 그걸 계속 구하면 풀 수
        // 있지 않을까...?

        string r, p; // p 가 최적알고리즘
        cin >> r >> p;
        int rSize = r.size();
        int pSize = p.size();
        if (rSize > 400 || pSize > 400) {
            continue;
        } else {
            vector<int> dp(rSize, rSize + 1);

            int k = 0;
            while ((k < rSize && k < pSize) && r[k] == p[k]) {
                dp[k] = 1;
                k++;
            }

            for (int i = 1; i < rSize; i++) {
                for (int j = i; j >= 1; j--) {
                    if (i - j + 1 > p.size())
                        break;
                    if (dp[j - 1] < dp[i] - 1) {
                        if (r.substr(j, i - j + 1) == p.substr(0, i - j + 1)) {
                            dp[i] = dp[j - 1] + 1;
                        }
                    }
                }
            }
            if (dp[rSize - 1] == rSize + 1)
                Answer = -1;
            else
                Answer = dp[rSize - 1];
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0; // Your program should return 0 on normal termination.
}