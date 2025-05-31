#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    int resp;
    scanf("%d", &n);
    printf("digit\n");
    fflush(stdout);
    scanf("%d", &resp);

    printf("digit\n");
    fflush(stdout);
    scanf("%d", &resp);
    printf("digit\n");
    fflush(stdout);
    scanf("%d", &resp);
    // now i know that the num is 1<=x<=9

    printf("div 2\n");
    fflush(stdout);
    scanf("%d", &resp);
    if (resp == 1) {
      // that means num is 1,2,3,4
      printf("div 2\n");
      fflush(stdout);
      scanf("%d", &resp);
      if (resp == 1) {
        // that mean num is 1,2
        printf("div 2\n");
        fflush(stdout);
        scanf("%d", &resp);
        if (resp == 1) {
          printf("add %d\n", n - 1);
          fflush(stdout);
          scanf("%d", &resp);
          printf("!\n");
          fflush(stdout);
          scanf("%d", &resp);
        } else {
          printf("add %d\n", n - 1);
          fflush(stdout);
          scanf("%d", &resp);
          printf("!\n");
          fflush(stdout);
          scanf("%d", &resp);
        }
      } else {
        // that mean num is 1,3
        printf("div 3\n");
        fflush(stdout);
        scanf("%d", &resp);
        if (resp == 1) {
          printf("add %d\n", n - 1);
          fflush(stdout);
          scanf("%d", &resp);
          printf("!\n");
          fflush(stdout);
          scanf("%d", &resp);
        } else {
          printf("add %d\n", n - 1);
          fflush(stdout);
          scanf("%d", &resp);
          printf("!\n");
          fflush(stdout);
          scanf("%d", &resp);
        }
      }
    } else {
      // that means num is 1,3,5,7,9
      printf("div 3\n");
      fflush(stdout);
      scanf("%d", &resp);
      if (resp == 1) {
        // that means num is 1,3
        printf("div 3\n");
        fflush(stdout);
        scanf("%d", &resp);
        if (resp == 1) {
          printf("add %d\n", n - 1);
          fflush(stdout);
          scanf("%d", &resp);
          printf("!\n");
          fflush(stdout);
          scanf("%d", &resp);
        } else {
          printf("add %d\n", n - 1);
          fflush(stdout);
          scanf("%d", &resp);
          printf("!\n");
          fflush(stdout);
          scanf("%d", &resp);
        }
      } else {
        // that means num is 1,5,7
        printf("div 5\n");
        fflush(stdout);
        scanf("%d", &resp);
        if (resp == 1) {
          printf("add %d\n", n - 1);
          fflush(stdout);
          scanf("%d", &resp);
          printf("!\n");
          fflush(stdout);
          scanf("%d", &resp);
        } else {
          printf("div 7\n");
          fflush(stdout);
          scanf("%d", &resp);
          if (resp == 1) {
            printf("add %d\n", n - 1);
            fflush(stdout);
            scanf("%d", &resp);
            printf("!\n");
            fflush(stdout);
            scanf("%d", &resp);
          } else {
            printf("add %d\n", n - 1);
            fflush(stdout);
            scanf("%d", &resp);
            printf("!\n");
            fflush(stdout);
            scanf("%d", &resp);
          }
        }
      }
    }
  }
}
