#include <bits/stdc++.h>
#include <utility>

using namespace std;

long long power2(int x) {
  if (x >= 60)
    return 0; // 2^60 >
  long long result = 1;
  long long base = 2;
  while (x > 0) {
    if (x & 1) {
      result = (result * base) % 998244353;
    }
    base = (base * base) % 998244353;
    x >>= 1;
  }
  return result;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> p;
    vector<pair<int, int>> maxp;
    vector<int> q;
    vector<long long> r;
    int maxpv = -1;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      if (a >= maxpv) {
        maxpv = a;
        maxp.push_back(pair(i, maxpv));
      } else {
        maxp.push_back(maxp.back());
      }
      p.push_back(a);
    }
    int maxqv = -1;
    int maxqi = 0;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      q.push_back(a);
      if (a > maxqv) {
        maxqv = a;
        maxqi = i;
      }
      long long maxr;
      if (maxqv > maxp[i].second) {
        long long a = power2(p[i - maxqi]);
        long long b = power2(q[maxqi]);
        maxr = (a + b) % 998244353;
      } else if (maxqv < maxp[i].second) {
        long long a = power2(p[maxp[i].first]);
        long long b = power2(q[i - maxp[i].first]);
        maxr = (a + b) % 998244353;
      } else {
        long long a = power2(p[i - maxqi]);
        long long b = power2(q[maxqi]);
        maxr = (a + b) % 998244353;

        a = power2(p[maxp[i].first]);
        b = power2(q[i - maxp[i].first]);
        maxr = max(maxr, (a + b) % 998244353);
      }
      // printf("maxr: %lld\n", maxr);
      printf("%llu", maxr);
      if (i < n - 1)
        printf(" ");
    }
    printf("\n");
  }
}
