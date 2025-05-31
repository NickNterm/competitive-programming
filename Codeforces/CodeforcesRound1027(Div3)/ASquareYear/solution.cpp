#include <bits/stdc++.h>
#include <cmath>
#include <math.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int n;
    scanf("%d", &n);
    int q = sqrt(n);
    if (q * q == n) {
      printf("%d %d\n", 0, q);
    } else {
      printf("-1\n");
    }
  }
}
