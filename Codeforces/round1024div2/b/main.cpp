#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <ios>

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
      v.push_back(a);
    }
    int num = abs(v[0]);
    if (v.size() == 1) {
      printf("YES\n");
      continue;
    }
    if (v.size() == 2) {
      printf("YES\n");
      continue;
    }
    v.push_back(-v[0]);

    sort(v.begin(), v.end());

    auto pos = find(v.begin(), v.end(), num);
    auto posNeg = find(v.begin(), v.end(), -num);
    long long a = posNeg - v.begin();

    long long b = pos - posNeg - 1;
    if (b < 0) {
      b = 0;
    }
    long long c = v.size() - (pos - v.begin()) - 1;
    // printf("a %d b %d c %d\n", a, b, c);

    // for the negative value
    if ((v.size() % 2 == 0 && a == b + c) ||
        (v.size() % 2 == 1 && a == c + b - 1)) {
      printf("YES\n");
      continue;
    } else {
      if ((v.size() % 2 == 0 && a - b + c > 0 && b + c - a > 0) ||
          (v.size() % 2 == 1 && a - b + c + 1 > 0 && b + c - a - 1 > 0)) {
        printf("YES\n");
        continue;
      }
    }
    // for the pos value
    if (a + b == c || a + b == c - 1) {
      printf("YES\n");
      continue;
    } else {
      if ((v.size() % 2 == 0 && a + b - c > 0 && a - b + c > 0) ||
          (v.size() % 2 == 1 && a + b - c + 1 > 0 && a - b + c - 1 > 0)) {
        printf("YES\n");
        continue;
      }
    }
    printf("NO\n");
  }
}
