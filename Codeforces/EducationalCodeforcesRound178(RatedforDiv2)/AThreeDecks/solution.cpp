#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int cardsToTake = c - b;
    int needsOnA = b - a;
    int remaining = cardsToTake - needsOnA;
    if (remaining >= 0) {
      if (remaining % 3 == 0) {
        printf("YES\n");
        continue;
      }
    }
    printf("NO\n");
  }
}
