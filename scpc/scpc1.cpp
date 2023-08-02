/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;

int getGCD(int a, int b) {
    // a > b
    if (a % b == 0) {
        return b;
    } else {
        return getGCD(b, a % b);
    }
}

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

        // 일단 최대 공약수 구하고 N A B 모두 최대공약수로 나눈다 이를 n, a,
        // b라고 하면. n = a*x + b*y 에서 a가 더 크다 가정할때 n/a >= Answer >=
        // n/b 이다. Answer을 최대한 큰걸 찾는 것이니깐 a*0 + b*(n//a) 부터
        // 시작해서 answer - b(t) (t=n//a에서 -1식 계속 감소) 하면서 a*x + b*y =
        // n이 되는 x, y를 찾으면 된다.
        int n, a, b, gcd; // a > b
        cin >> n >> a >> b;
        if (a < b) {
            gcd = a;
            a = b;
            b = gcd;
        }
        gcd = getGCD(a, b);
        a /= gcd;
        b /= gcd;
        n /= gcd;

        int t = n / b;
        for (int i = t; i >= 0; i--) {
            if ((n - b * i) % a == 0) {
                Answer = i + (n - b * i) / a;
                break;
            }
        }

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0; // Your program should return 0 on normal termination.
}