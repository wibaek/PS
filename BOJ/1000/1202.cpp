#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // 보석, 가방
    int a, b;
    vector<pair<int, int>> gem; // 무게, 가격
    vector<int> bag;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        gem.push_back(make_pair(a, b));
    }
    for (int i = 0; i < k; i++) {
        cin >> a;
        bag.push_back(a);
    }

    // 둘다 크기순 정렬
    sort(bag.begin(), bag.end());
    sort(gem.begin(), gem.end());

    int gemCur{0};
    priority_queue<int> pq;
    long long answer{0};
    // 작은 가방부터 탐색하면서 들어갈 수 있는 보석들을 계속 pq에 기록? 저장.
    for (int i = 0; i < k; i++) {
        // 0번 가방부터 k-1번 가방까지 넣을 수 있는 최대 크기의 보석을 계속 pq에
        // 저장
        while (gem[gemCur].first <= bag[i] && gemCur < n) {
            pq.push(gem[gemCur].second);
            gemCur++;
        }
        if (pq.size() > 0) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
    return 0;
}
