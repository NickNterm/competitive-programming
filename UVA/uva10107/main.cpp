#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  vector<int> list;
  while (scanf("%d", &n) == 1) {
    list.push_back(n);
    auto mid = list.begin() + list.size() / 2;
    if (list.size() % 2 == 0 && list.size() > 1) {
      nth_element(list.begin(), mid, list.end());
      nth_element(list.begin(), mid - 1, list.end());
      int res = (list[list.size() / 2] + list[list.size() / 2 - 1]) / 2;
      printf("%d\n", res);
    } else {
      nth_element(list.begin(), mid, list.end());
      printf("%d\n", list[list.size() / 2]);
    }
  }
}
