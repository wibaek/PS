#include <iostream>
#include <string>
#include <queue>
using namespace std;
// Class queue{
//     queue(int size) {

//     }

// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string query;
    int num;
    queue<int> q;
    cin >> N;

    for(int i=0; i<N; ++i) {
        cin >> query;

        if(query == "push") {
            cin >> num;
            q.push(num);
        }
        else if(query == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(query == "size") {
            cout << q.size() << "\n";
        }

        else if(query == "empty") {
            if (q.empty()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if(query == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        else if(query == "back") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
    return 0;
}
