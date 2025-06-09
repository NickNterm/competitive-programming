#include <bits/stdc++.h>
#include <cstdio>
#include <deque>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    deque<int> a;
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        a.push_back(n - i);
      } else {
        a.push_front(n - i);
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%d", a[i]);
      if (i != n - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}
