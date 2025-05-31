#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> res;
    for (int i = 0; i < x; i++) {
      res.push_back(i);
    }
    for (int i = (int)res.size() + 1; i < n; i++) {
      res.push_back(i);
    }
    res.push_back(x);
    for (int i = 0; i < n; i++) {
      printf("%d ", res[i]);
    }
    printf("\n");
  }
}
