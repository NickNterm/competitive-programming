#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long x, y, z;
    scanf("%llu %llu %llu", &x, &y, &z);
    if ((x ^ y) == z) {
      long long count = __builtin_popcountll(z);
      if (count == 0) {
        printf("1\n");
        continue;
      } else {
        long long ans = 1;
        for (int i = 0; i < 30; ++i) {
          int xb = (x >> i) & 1;
          int yb = (y >> i) & 1;
          if (xb == 1 && yb == 0) {
            ans = 0;
            break;
          }
          if (xb == 0 && yb == 1) {
            ans *= 2;
          }
        }
        printf("%lld\n", ans);
      }
    } else {

      printf("0\n");
    }
  }
}
