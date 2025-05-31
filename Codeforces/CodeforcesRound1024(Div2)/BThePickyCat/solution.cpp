#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int num;
    scanf("%d", &num);
    int countBefore = 0;
    int countAfter = 0;
    for (int i = 1; i < n; i++) {
      int a;
      scanf("%d", &a);
      v.push_back(abs(a));
      if (abs(a) < abs(num)) {
        countBefore++;
      } else if (abs(a) > abs(num)) {
        countAfter++;
      }
    }
    if (countBefore >= ceil(n / 2) + 1) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
}
