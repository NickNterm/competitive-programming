#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> v;
    int last = -1;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      if (a - 1 > last) {
        v.push_back(a);
        last = a;
      }
    }
    printf("%d\n", (int)v.size());
  }
}
