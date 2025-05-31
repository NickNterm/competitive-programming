#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> list;
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d ", &c);
    list.push_back(c);
  }

  sort(list.begin(), list.end());

  int mid;
  if (n % 2) {
    mid = n / 2;
  } else {
    mid = n / 2 - 1;
  }
  long int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i > mid) {
      sum += list[i];
    } else if (i == mid) {
      if (n % 2 == 0) {
        sum -= list[i];
      } else {
        sum += list[i];
      }
    } else {
      sum -= list[i];
    }
  }
  printf("%ld\n", sum);
}
