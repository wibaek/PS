#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Person {
    int weight;
    int height;
    int biggerCount;
};

bool comparePerson(const Person &p1, const Person &p2) {
    return (p1.weight < p2.weight) && (p1.height < p2.height);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a, b;
    vector<Person> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        Person person;
        cin >> person.weight >> person.height;
        v.push_back(person);
    }

    // 자기보다 덩치큰 사람 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (comparePerson(v[i], v[j]))
                v[i].biggerCount++;
        }
    }

    // vector<int> biggerCountCount(
    //     51); // 각 "자기보다 큰 덩치의 개수"가 몇개씩 있는지
    // for (Person p : v) {
    //     biggerCountCount[p.biggerCount]++;
    // }

    // int count = 1;
    // vector<int> ranking(51); // 각 "자기보다 큰 덩치의 개수"가 몇등인지 측정
    // for (int i = 0; i <= 50; i++) {
    //     ranking[i] = count;
    //     count += biggerCountCount[i];
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << ranking[v[i].biggerCount] << " ";
    // }
    for (int i = 0; i < n; i++) {
        cout << v[i].biggerCount + 1 << " ";
    }

    return 0;
}
