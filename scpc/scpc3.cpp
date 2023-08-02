/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;

bool isRepeat(vector<int> &v, int i) {
    // 반복되는 상태가 i개 존재한다면 각 반복하는 순열의 사이즈 t = n/i
    // const int t = v.size() / i; // 각 반복되는 순열의 사이즈
    for (int j = 0; j < i; j++) {
        for (int k = j; k < v.size(); k += i) {
            if (v[j] != v[k])
                return false;
        }
    }
    return true;
}

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
        // 일단 먼가 느낌이 총 쇠구슬의 개수보다 칸수가 많거나 같으면 결국
        // 평형을 이루는 방식으로 돌아가고 평형이 된다면 상태의 수는 칸의 수랑
        // 동일해짐. 동일...해지나? 아닐수도, 아닐수도있네. 암튼
        // 이건 먼가 대칭성의 느낌으로.. 어캐 구별하지.
        // 일단 조건을 보자
        // 태캐 509, 칸수 50만, 구슬 10억? 돌아버린것?, 총 칸수n의 합 350만...
        // 대충 칸보다 구슬이 많은 형식이네요. 일단 제 추측으로는 어짜피 남는
        // 구슬은 평형을 이루게 됨
        // 즉 A%n 해서 남는 나머지로만 결국 따지게 될거라는거.
        // 약간 생명 게임의 느낌이 나네
        //
        // 이걸 어캐 풀지? 일단 느낌상 한 칸에 쌓인 Ai의 개수가 n개 이상이면
        // Ai%n해도 될것 같은데,
        // 왜냐면 이제 각 구슬을 별개로 생각하면서 생각하면 이제 결국 그
        // 구슬들은 한 바퀴 돌떄까지 안없어진다고 볼 수 있달까나요..? 아닌가
        // 내가 무슨말 하는지 모르겠고 일단 이건 그냥 적고 있는거긴 한데

        // 일단 최적화 완료 후에 평형상태를 유지한후 몇가지 패턴이 나타나는지
        // 체크하는 알고리즘과 최적화 하는 알고리즘이 필요함. 그니깐 약간
        // 카오스상태가 평형이 된후에 반복되게 되는데 이 카오스 상태 끝나는
        // 상태를 계산하는 알고리즘.

        // 잘못깨달았다. 칸이 다차는 순간부터 그걸
        // 지우는게 아니라 그냥 그 상태로 영원히 유지되는거임. 그니깐 행동은
        // 많아봐야 50만번 돌리면 평형으로 돌아간다, 다찬다는 가정하에
        int n, t;
        bool isGroup2 = true;
        long long int total = 0;
        vector<int> v;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            v.push_back(t);
            total += t;
            if (t > 1) {
                isGroup2 = false;
            }
        }
        if (isGroup2) {
            Answer = n;
            // 기본적으로 일단 모든 순열은 반복이 아에 없다면 반복되는 상태가
            // N개 존재함 그리고 모든 원소가 상태가 같다면 반복되는 상태가 1개
            // 존재함. 즉 한마디로 어느 순열도 반복되는 상태가 최대 N개 존재함.
            for (int i = n - 1; i >= 1; i--) {
                if (n % i == 0) {
                    if (isRepeat(v, i)) {
                        Answer = i;
                    }
                }
            }
        } else if (total >= n) {
            Answer = 1;
        } else {
            Answer = 1;
        }
        // 느낌상 Ai > 1 인 경우에 이제 사이클을 N번 돌리면 AiTotal <= N이라는
        // 가정하에 모든 Ai <= 1이 될것 같은데? 그럼 50만번 기준으로 50만번만
        // 돌려주면 되...나? 25000억 ㅇㅅㅇ...? 일단 패스

        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0; // Your program should return 0 on normal termination.
}