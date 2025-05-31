#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    long long a, b, c, d;
    scanf("%llu %llu %llu %llu", &a, &b, &c, &d);
    long long minHPG = min(a, c);
    long long minHPF = min(b, d);
    if (minHPG < minHPF) {
      printf("Flower\n");
    } else {
      printf("Gellyfish\n");
    }
  }
}
