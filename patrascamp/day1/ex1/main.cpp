#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc = 0;
  scanf("%d", &tc);

  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> list;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d ", &a);
      list.push_back(a);
    }
    sort(list.begin(), list.end());
    int hasSolution = 0;

    do {
      int sum = 0;
      int found = 0;
      for (int i = 0; i < n; i++) {
        sum += list[i];
        if (sum % 3 == 0) {
          break;
        } else {
          found++;
        }
      }
      if (found == n) {
        hasSolution = 1;
        for (int i = 0; i < n; i++) {
          printf("%d ", list[i]);
        }
        printf("\n");
        break;
      }
    } while (next_permutation(list.begin(), list.end()));
    if (hasSolution == 0) {
      printf("-1\n");
    }
  }
}
