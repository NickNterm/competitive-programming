#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using ll = long long;

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> v;
    vector<int> m;
    vector<ll> res;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      v.push_back(a);
      if (i == 0) {
        m.push_back(a);
      } else {
        m.push_back(max(m[i - 1], a));
      }
      sum += a;
    }
    // res.push_back(sum);
    for (int k = 0; k < n; k++) {
      sum -= v[k];
      // printf("SUM IS %lld\n", sum);
      int maxElement = m[k];
      res.push_back(sum + maxElement);
    }
    for (int i = n - 1; i >= 0; i--) {
      if (i != 0)
        printf("%lld ", res[i]);
      else
        printf("%lld", res[i]);
    }
    printf("\n");
  }
}
