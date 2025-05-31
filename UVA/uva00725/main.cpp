#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int f = 0;
  while (true) {
    int n;
    cin >> n;
    if (n == 0)
      break;
    if (f == 0) {
      f = 1;

    } else {
      printf("\n");
    }

    int found = 0;
    for (int fghij = 1234; fghij <= 98765 / n; fghij++) {
      int abcde = fghij * n;
      int used = (fghij < 10000);
      int temp = fghij;
      while (temp) {
        used |= 1 << (temp % 10);
        temp = temp / 10;
      }

      temp = abcde;
      while (temp) {
        used |= 1 << (temp % 10);
        temp = temp / 10;
      }

      // printf("%b\n", used);
      if (used == (1 << 10) - 1) {
        // cout << abcde << " / " << fghij << " = " << n << endl;
        found = 1;
        printf("%05d / %05d = %d\n", abcde, fghij, n);
      }
    }
    if (!found) {
      printf("There are no solutions for %d.\n", n);
    }
  }
}
