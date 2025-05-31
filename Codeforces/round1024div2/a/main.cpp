#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m, p, q;
    scanf("%d %d %d %d", &n, &m, &p, &q);
    int a = n / p;
    int x = n % p;
    // printf("A %d X %d\n ", a, x);
    if (x == 0) {
      if (n / p * q == m) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    } else {
      printf("YES\n");
    }
  }
}
