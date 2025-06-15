#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long k, a, b, x, y;
    scanf("%ld %ld %ld %ld %ld", &k, &a, &b, &x, &y);
    long meals1 = 0;
    long meals2 = 0;
    long k1 = k;
    if (k1 >= a) {
      long c = (k1 - a) / x + 1;
      meals1 += c;
      // printf("C1:%d\n", c);
      k1 -= x * c;
      if (k1 >= b) {
        c = (k1 - b) / y + 1;
        if (c > 0) {
          // printf("C2:%d\n", c);
          meals1 += c;
          k1 -= y * c;
        }
      }
    }
    long k2 = k;
    if (k2 >= b) {
      long c = (k2 - b) / y + 1;
      meals2 += c;
      // printf("C3:%d\n", c);
      k2 -= y * c;
      if (k2 >= a) {
        long c = (k2 - a) / x + 1;
        if (c > 0) {
          // printf("C4:%d\n", c);
          meals2 += c;
          k2 -= x * c;
        }
      }
    }
    printf("%ld\n", max(meals1, meals2));
  }
}
