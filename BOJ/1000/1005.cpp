#include <iostream>
#include <queue>
// #include <string>
#include <vector>
using namespace std;

class Building {
  public:
    Building(int id, int timeCost) {
        this->id = id;
        this->timeCost = timeCost;
        this->prevTimeSpend = 0;
        this->prevBuildingCount = 0;
    }
    int id;
    int timeCost;
    int prevTimeSpend;
    int prevBuildingCount;
    vector<Building *> next;
    vector<Building *> prev;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, K, W, a, b;
    cin >> T;
    while (T--) {
        // 입력
        cin >> N >> K;
        vector<Building *> buildings;
        for (int i = 0; i < N; i++) {
            cin >> a;
            buildings.push_back(new Building(i + 1, a));
        }
        for (int i = 0; i < K; i++) {
            cin >> a >> b;
            buildings[a - 1]->next.push_back(buildings[b - 1]);
            buildings[b - 1]->prev.push_back(buildings[a - 1]);
            buildings[b - 1]->prevBuildingCount++;
        }
        cin >> W;

        // 풀이
        queue<Building *> q;
        // 선행 요구 건물이 없는 건물들을 큐에 추가
        for (int i = 0; i < N; i++) {
            if (buildings[i]->prev.size() == 0)
                q.push(buildings[i]);
        }
        // queue를 돌면서
        while (q.size() != 0) {
            Building *building = q.front();
            q.pop();
            // 만약 목표 건물이라면 break
            if (building->id == W) {
                break;
            }

            for (int i = 0; i < building->next.size(); i++) {
                building->next[i]->prevTimeSpend =
                    max(building->prevTimeSpend + building->timeCost,
                        building->next[i]->prevTimeSpend);
                building->next[i]->prevBuildingCount--;
                // 더 이상 요구 건물이 없으면 큐에 추가
                if (building->next[i]->prevBuildingCount == 0)
                    q.push(building->next[i]);
            }
        }
        cout << buildings[W - 1]->prevTimeSpend + buildings[W - 1]->timeCost
             << endl;
        // 빌딩 할당 해제
        for (int i = 0; i < N; i++) {
            delete buildings[i];
        }
    }
    return 0;
}
