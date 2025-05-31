#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);
    long long gcd = __gcd(y, x);
    long long a = gcd / y;
    long long b = gcd / x;
  }
}
