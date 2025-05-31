#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;

  scanf("%d", &tc);

  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> v;
    int aces = 0;
    bool isDouble0 = false;
    int last = -1;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      if (a == 0 && last == 0) {
        isDouble0 = true;
      }
      last = a;
      if (a == 1) {
        aces++;
      }
    }
    if (aces == 0) {
      printf("YES\n");
      continue;
    }
    if (aces == n) {
      printf("YES\n");
      continue;
    }

    if (isDouble0) {
      printf("YES\n");
      continue;
    }
    printf("NO\n");
  }
}
