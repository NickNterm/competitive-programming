#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int x;
    scanf("%d", &x);
    int flag = 0;
    char str[200005];
    scanf("%s", str);
    if (str[strlen(str) - 1] == '\n') {
      str[strlen(str) - 1] = '\0';
    }
    int len = strlen(str);
    if (len == 2) {
      printf("NO\n");
      continue;
    }
    regex pattern(R"(\({2,}(\(\))+\){2,})");
    if (regex_match(str, pattern)) {
      printf("NO\n");
      continue;
    }
    for (int i = 0; i < len; i++) {
      char a = str[i];
      if (a == '(' && flag == 0) {
        flag = 1;
      } else if (a == ')' && flag == 1) {
        flag = 2;
      } else if (a == '(' && flag == 2) {
        flag = 3;
      }
    }
    if (flag == 3) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
