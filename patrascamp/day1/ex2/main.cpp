#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {

  int days = 0;
  vector<int> visit_days;
  int books = 0;
  vector<int> max_buffer_days;
  vector<int> max_price;
  scanf("%d", &days);
  for (int i = 0; i < days; i++) {
    int tmp = 0;
    scanf("%d", &tmp);
    visit_days.push_back(tmp);
  }

  scanf("%d", &books);
  for (int i = 0; i < books; i++) {
    int tmp;
    scanf("%d", &tmp);
    max_buffer_days.push_back(tmp);
  }

  for (int i = 0; i < books; i++) {
    int tmp;
    scanf("%d", &tmp);
    max_price.push_back(tmp);
  }

  long int res = 0;
  for (int i = 0; i < books; i++) {
    long int closesta;
    long int closestb;
    long int closest_distance = LONG_MAX;
    for (int a = 0; a < days; a++) {
      int daya = visit_days[a];
      for (int b = a; b < days; b++) {
        int dayb = visit_days[b];
        if (abs(dayb - (daya + max_buffer_days[i])) < closest_distance) {
          closest_distance = abs(dayb - (daya + max_buffer_days[i]));
          closesta = daya;
          closestb = dayb;
        }
      }
      if (closest_distance == 0) {
        break;
      }
    }
    res += max_price[i] - abs(closestb - (closesta + max_buffer_days[i])) > 0
               ? max_price[i] - abs(closestb - (closesta + max_buffer_days[i]))
               : 0;
  }

  printf("%ld\n", res);

  return 0;
}
