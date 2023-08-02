/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char **argv) {
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
        int n, d, temp;
        vector<int> a;
        vector<int> b;
        cin >> n >> d;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp < 0) {
                b.push_back(-temp);
            } else {
                a.push_back(temp);
            }
        }
        a.push_back(0);
        b.push_back(0);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ap = a.size() - 1;
        int bp = 0;

        while ((ap > 0) && (a[ap] > d)) {
            ap--;
        }

        for (int i = ap; i >= 0; i--) {
            while ((bp + 1 < b.size()) && ((d - 2 * a[i] - b[bp + 1] >= 0) ||
                                           (d - 2 * b[bp + 1] - a[i] >= 0))) {
                bp++;
            }
            Answer = max(Answer, i + bp);
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0; // Your program should return 0 on normal termination.
}