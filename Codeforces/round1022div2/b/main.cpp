#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long n, x;
    scanf("%lld %lld", &n, &x);
    int bitcount = 0;
    int t = x;
    while (t) {
      bitcount += t & 1;
      t = t >> 1;
    }
    if (bitcount < n) {
      if ((bitcount - n) % 2 == 0) {
        printf("%lld\n", x + n - bitcount);
      } else {
        if (x > 1) {
          printf("%lld\n", x + (n - bitcount) + 1);
        } else if (x == 1) {
          printf("%lld\n", n + 3);
        } else if (x == 0) {
          if (n == 1) {
            printf("-1\n");
          } else {
            printf("%lld\n", n + 3);
          }
        }
      }
    } else {
      printf("%lld\n", x);
    }
  }
}
