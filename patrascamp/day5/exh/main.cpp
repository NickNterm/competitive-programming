#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int n, c;
  scanf("%d %d\n", &n, &c);
  deque<int> list;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    list.push_back(a);
  }

  if (c == 1) {
    int a = 0;
    int b = n - 1;
    int aValue;
    int bValue;
    aValue = list.back();
    bValue = list.front();
    list.pop_back();
    list.pop_front();
    while (true) {
    }
  }
}
