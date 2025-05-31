#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  if (n == 1) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y) {
      long long square = (x - 1) * (x - 1);

      if (x % 2 != 0) {
        square += y;
      } else {
        square += 2 * x - y;
      }
      printf("%llu\n", square);
    } else {
      long long square = (y - 1) * (y - 1);

      if (y % 2 == 0) {
        square += x;
      } else {
        square += 2 * y - x;
      }
      printf("%llu\n", square);
    }
  } else {
    long long k;
    scanf("%llu", &k);
    long long x = ceil(sqrt(k));
    long long y = (x * x) - k + 1;
    if (x % 2 == 0) {
      if (y > x) {
        printf("%llu %llu\n", x - (y - x), x);
      } else {
        printf("%llu %llu\n", x, y);
      }
    } else {
      if (x > y) {
        printf("%llu %llu\n", y, x);
      } else {
        printf("%llu %llu\n", x, x - (y - x));
      }
    }
  }
}
