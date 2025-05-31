#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  while (tc--) {
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    if (n > 1) {
      // i need to split the x axis.
      int firstCut = a;
      if (firstCut > n / 2) {
        firstCut = a - 1;
      }
    }
  }
}
