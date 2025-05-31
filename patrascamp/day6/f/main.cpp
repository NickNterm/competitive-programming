#include <bits/stdc++.h>
#include <vector>

#define int long long
#define double long double
using namespace std;

vector<vector<int>> dp; // 23279256000
void helper(vector<int> list, int element, int target, vector<int> &result) {
  if (target == list[element]) {
    result.push_back(element);
    return;
  }
  for (int i = element + 1; i < list.size(); i++) {
    helper(list, i, target, vector<int>(result));
  }
}

signed main() {
  int n;
  scanf("%lld", &n);
  vector<tuple<int, int, double, int>> deck;
  for (int i = 0; i < n; i++) {
    int p;
    int q;
    scanf("%lld %lld", &p, &q);
    double div = (double)p / q;
    tuple<int, int, double, int> tmp = {p, q, div, i};
    deck.push_back(tmp);
  }

  int target = 0;
  for (int i = 0; i < n; i++) {
    int q = get<1>(deck[i]);
    if (target == 0) {
      target = q;
    } else {
      target = (target * q) / __gcd(target, q);
    }
  }

  vector<int> kosinas;
  for (int i = 0; i < n; i++) {

    int tmp0 = get<0>(deck[i]);
    int tmp1 = get<1>(deck[i]);
    int tmp = tmp0 * (target / tmp1);
    kosinas.push_back(tmp);
  }

  for (int i = 0; i < n; i++) {
    helper(kosinas, i, target);
  }

  printf("NO\n");
  return 0;
}
