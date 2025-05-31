#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    char s[200005] = "";
    scanf("%s", s);
    int ones = 0;
    for (char c : s) {
      if (c == '1') {
        ones++;
      }
    }
    int zeros = n - ones;
    int missingpairs = (n / 2) - m;
    zeros = zeros - missingpairs;
    ones = ones - missingpairs;
    if (zeros >= 0 && ones >= 0 && zeros % 2 == 0 && ones % 2 == 0) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
