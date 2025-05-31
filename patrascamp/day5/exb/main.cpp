#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, s, r;
    int currMoney = 0;
    vector<int> income;
    scanf("%d %d %d", &n, &s, &r);
    int finish = 0;
    // printf("%d %d %d\n", n, s, r);
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      income.push_back(a);
      currMoney += a;
      if (currMoney < 0) {
        printf("-1\n");
        finish = 1;
        int d;
        i++;
        for (i; i < n; i++) {
          scanf("%d", &a);
          income.push_back(a);
        }
        break;
      } else if (currMoney >= s) {
        printf("%d\n", i + 1);
        int d;
        i++;
        for (i; i < n; i++) {
          scanf("%d", &a);
          income.push_back(a);
        }
        finish = 1;
        break;
      }
      s += r;
    }

    if (!finish) {
      printf("-1\n");
    }
  }
}
