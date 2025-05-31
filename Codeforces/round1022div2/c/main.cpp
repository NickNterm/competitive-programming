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
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      if (v.size() >= 1) {
        if (v.back() != a) {
          v.push_back(a);
        }
      } else {
        v.push_back(a);
      }
    }
    n = v.size();
    // for (int i = 0; i < n; i++) {
    //   printf("%d ", v[i]);
    // }
    // printf("\n");
    int ans;
    if (v.size() == 1) {
      ans = 1;
    } else if (v.size() == 2) {
      ans = 1;
    } else {
      ans = 0;
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          if (v[i] - v[i + 1] >= 1) {
            ans++;
          }
        } else if (i == n - 1) {
          if (v[i] - v[i - 1] >= 1) {
            ans++;
          }
        } else {
          if (v[i] - v[i - 1] >= 1 && v[i] - v[i + 1] >= 1) {
            ans++;
          }
        }
      }
    }

    printf("%d\n", ans);
  }
}
