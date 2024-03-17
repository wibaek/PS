#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int profitTable[10000]
               [300]; // profitTable[i][j] = i+1번 가게에서 j+1번 직원이 낸 매출
int maxProfit[10000];        // n번 가게에서 최대 매출
int bestSellerCount[300];    // 매출왕 수
int marketBestSeller[10000]; // i번 가게의 매출왕

int countBestSeller(int employeeCount, int chargeCount) {
  int count = 0;
  for (int i = 0; i < employeeCount; i++) {
    if (bestSellerCount[i] == chargeCount) {
      count++;
    }
  }
  return count;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int employeeCount, marketCount, chargeCount;
  cin >> employeeCount >> marketCount >> chargeCount;

  for (int i = 0; i < employeeCount; i++) {
    for (int j = 0; j < chargeCount; j++) {
      int market, profit;
      cin >> market >> profit;
      profitTable[market - 1][i] = profit;
      maxProfit[market - 1] = max(maxProfit[market - 1], profit);
    }
  }

  for (int i = 0; i < marketCount; i++) {
    if (maxProfit[i] == 0) {
      continue;
    }
    for (int j = 0; j < employeeCount; j++) {
      if (profitTable[i][j] == maxProfit[i]) {
        ++bestSellerCount[j];
        marketBestSeller[i] = j;
        break;
      }
    }
  }

  int tasks;
  cin >> tasks;

  for (int i = 0; i < tasks; i++) {
    int employee, market, profit;
    cin >> employee >> market >> profit;
    market--;
    employee--;

    if (marketBestSeller[market] == employee) {
      profitTable[market][employee] += profit;
      maxProfit[market] = profitTable[market][employee];
    } else {
      profitTable[market][employee] += profit;
      if (profitTable[market][employee] > maxProfit[market]) {
        maxProfit[market] = profitTable[market][employee];
        bestSellerCount[marketBestSeller[market]]--;
        marketBestSeller[market] = employee;
        bestSellerCount[employee]++;
      }
    }

    cout << countBestSeller(employeeCount, chargeCount) << endl;
  }

  return 0;
}
