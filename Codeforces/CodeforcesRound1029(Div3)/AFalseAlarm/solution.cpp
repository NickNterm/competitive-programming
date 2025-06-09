#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int f1 = -1;
    int f2 = -1;
    // vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      if (f1 == -1 && x == 1) {
        f1 = i;
      }
      if (x == 1) {
        f2 = i;
      }
      // a.push_back(x);
    }
    if (f2 - f1 >= m) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
}
