#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  forward_list<char> text;
  auto pushPos = text.before_begin();
  char line[1000001];
  while (scanf("%s", line) != EOF) {
    for (int i = 0; i < strlen(line); i++) {
      char c = line[i];
      if (c == '[') {
        pushPos = text.before_begin();
      } else if (c == ']') {
        for (auto next = text.begin(); next != text.end(); ++next) {
          pushPos = next;
        }
      } else {
        text.insert_after(pushPos, c);
        pushPos++;
      }
    }

    for (auto c : text) {
      printf("%c", c);
    }
    printf("\n");
    text.clear();
    pushPos = text.before_begin();
  }
}
