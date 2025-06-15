#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {

    long w, h, a, b;
    scanf("%ld %ld %ld %ld", &w, &h, &a, &b);
    long x1, y1, x2, y2;
    scanf("%ld %ld %ld %ld", &x1, &y1, &x2, &y2);
    long top1, bottom1, left1, right1;
    long top2, bottom2, left2, right2;

    top1 = y1 + b;
    bottom1 = y1;
    left1 = x1;
    right1 = x1 + a;
    top2 = y2 + b;
    bottom2 = y2;
    left2 = x2;
    right2 = x2 + a;

    if ((top1 > bottom2 && top1 - bottom2 < b) ||
        (top2 > bottom1 && top2 - bottom1 < b) || top1 == top2) {
      // printf("1\n");
      if (right1 != left2 && right2 != left1) {
        if (right1 < left2) {
          if ((left2 - right1) % a != 0) {
            printf("No\n");
            continue;
          }
        }
        if (right2 < left1) {
          if ((left1 - right2) % a != 0) {
            printf("No\n");
            continue;
          }
        }
      }
    }
    if ((left1 > right2 && left1 - right2 < a) ||
        (left2 > right1 && left2 - right1 < a) || left1 == left2) {
      // printf("2\n");
      if (top1 != bottom2 && top2 != bottom1) {
        if (top1 < bottom2) {
          // printf("3\n");
          // printf("!%d %d\n", top1, bottom2);
          if ((bottom2 - top1) % b != 0) {
            printf("No\n");
            continue;
          }
        }
        if (top2 < bottom1) {
          if ((bottom1 - top2) % b != 0) {
            printf("No\n");
            continue;
          }
        }
      }
    }
    printf("Yes\n");
  }
}
