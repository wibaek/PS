#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
};

struct compare {
    bool operator()(Edge *a, Edge *b) { return a->weight > b->weight; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<vector<Edge *>> nodeList(v + 1);

    int a, b, c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        nodeList[a].push_back(new Edge{a, b, c});
        nodeList[b].push_back(new Edge{b, a, c});
    }

    priority_queue<Edge *, vector<Edge *>, compare> pq;

    // 프림 알고리즘

    int includeCounter = 1;
    vector<bool> includeList(v + 1);
    includeList[1] = true;
    for (Edge *edge : nodeList[1]) {
        pq.push(edge);
    }
    int answer = 0;
    while (includeCounter < v) {
        Edge *edge = pq.top();
        pq.pop();
        if (includeList[edge->dest]) {
            continue;
        } else {
            includeList[edge->dest] = true;
            includeCounter++;
            answer += edge->weight;
            for (Edge *e : nodeList[edge->dest]) {
                if (!includeList[e->dest])
                    pq.push(e);
            }
        }
    }
    cout << answer;
    return 0;
}
