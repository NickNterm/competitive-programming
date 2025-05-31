#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

int calcHelper(int i, int j, vector<int> v) {
  if ((v[i] + v[j]) % 2 == 0) {
    // printf("%d %d\n", i, j);
    return j - i;
  } else {
    return max(calcHelper(i, j - 1, v), calcHelper(i + 1, j, v));
  }
}

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    printf("%d\n", n - calcHelper(0, n - 1, v) - 1);
  }
}
