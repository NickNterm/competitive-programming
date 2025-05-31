#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#include <unordered_set>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    vector<int> v;
    unordered_set<int> resset;
    scanf("%d", &n);
    int m = INT_MIN;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      m = max(m, a);
      v.push_back(a);
      resset.insert(a);
    }

    if (resset.size() > 1) {
      printf("Yes\n");
      for (int i = 0; i < n; i++) {
        if (v[i] == m) {
          printf("%d ", 1);
        } else {
          printf("%d ", 2);
        }
      }
      printf("\n");
    } else {
      printf("No\n");
    }
  }
}
