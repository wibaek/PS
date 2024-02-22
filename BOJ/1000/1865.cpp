#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int s, e, t;
};

void solution() {
    int n, m, w;
    int s, e, t;
    cin >> n >> m >> w;
    // 간선 생성
    vector<edge> edges;

    // 도로 정보 입력
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        edges.push_back({s, e, t});
        edges.push_back({e, s, t});
    }
    // 웜홀 정보 입력
    for (int i = 0; i < w; i++) {
        cin >> s >> e >> t;
        edges.push_back({s, e, -t});
    }

    // 정점까지의 최단거리
    vector<int> dist(n + 1, 1e9);

    // 벨만포드 알고리즘
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto edge : edges) {
            if (dist[edge.e] > dist[edge.s] + edge.t) {
                dist[edge.e] = dist[edge.s] + edge.t;
            }
        }
    }

    // 음수 사이클 존재 여부
    bool is_cycle = false;
    for (auto edge : edges) {
        if (dist[edge.e] > dist[edge.s] + edge.t) {
            is_cycle = true;
            break;
        }
    }

    if (is_cycle) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count;
    cin >> count;
    while (count--) {
        solution();
    }

    return 0;
}
