#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    string query;
    vector <double> stack;
    cin >> N >> query;
    double* nums = new double[N];
    
    for(int i=0; i< N; ++i) cin >> nums[i];

    for(int i =0; i<(int)query.size(); ++i) {
        if (query[i] >= 'A' && query[i] <= 'Z') {
            stack.push_back(nums[query[i] - 'A']);
        }
        else {
            double a = stack.back();
            stack.pop_back();
            double b = stack.back();
            stack.pop_back();

            if (query[i] == '+') {
                stack.push_back(b+a);
            }
            else if (query[i] == '-'){
                stack.push_back(b-a);
            }
            else if (query[i] == '*'){
                stack.push_back(b*a);
            }
            else if (query[i] == '/'){
                stack.push_back(b/a);
            }
        }
    }
    cout << fixed << setprecision(2) << stack.back();
}
