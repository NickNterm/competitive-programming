#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> v;
    long long sum = 0;
    int emax = INT_MIN;
    int emin = INT_MAX;

    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      sum += a;
      emax = max(emax, a);
      emin = min(emin, a);
      v.push_back(a);
    }

    sort(v.begin(), v.end());
    v[n - 1]--;
    sort(v.begin(), v.end());

    if ((v[n - 1] - v[0]) > k) {
      printf("Jerry\n");
    } else {
      if (sum % 2) {
        printf("Tom\n");
      } else {
        printf("Jerry\n");
      }
    }
  }
}
