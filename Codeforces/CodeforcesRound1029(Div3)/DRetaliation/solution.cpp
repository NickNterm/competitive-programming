#include <bits/stdc++.h>
using namespace std;

bool solved(const vector<int> &a, int n) {
  int dif = a[1] - a[0];
  int off = a[0] - dif;

  for (int i = 0; i < n; ++i) {
    if (a[i] != dif * (i + 1) + off)
      return false;
  }

  if (off % (n + 1) != 0)
    return false;

  int y = off / (n + 1);
  int x = dif + y;

  return x >= 0 && y >= 0;
}

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }

    if (solved(a, n)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
