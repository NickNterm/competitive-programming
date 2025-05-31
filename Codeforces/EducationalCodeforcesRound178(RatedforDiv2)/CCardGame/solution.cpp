#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<int> a;
    char s[50];
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A')
        a.push_back(i + 1);
    }
    // for (int i = 0; i < a.size(); i++) {
    //   printf("%d", a[i]);
    // }
    // printf("\n");
    if (a.empty()) {
      printf("Bob\n");
      continue;
    }
    if (a.size() == n) {
      printf("Alice\n");
      continue;
    }
    if (n - a.size() > 1 && s[n - 1] == 'B') {
      printf("Bob\n");
      continue;
    }
    if (s[0] == 'B' && s[n - 2] == 'B') {
      printf("Bob\n");
      continue;
    }
    if (s[0] == 'B' && s[n - 2] == 'B') {
      printf("Bob\n");
      continue;
    }
    if (s[n - 1] == 'B' && s[n - 2] == 'B') {
      printf("Bob\n");
      continue;
    }
    printf("Alice\n");
  }
}
