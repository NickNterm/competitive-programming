#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);

  while (tc--) {
    int n;
    scanf("%d", &n);
    set<int> elementsToFind;
    set<int> newelemensToFind;
    int subArrays = 0;
    set<int> found;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      newelemensToFind.insert(x);
      if (elementsToFind.find(x) != elementsToFind.end()) {
        found.insert(x);
      }
      if (found.size() == elementsToFind.size()) {

        found.clear();
        subArrays++;
        elementsToFind = newelemensToFind;
        // elementsToFind.insert(newelemensToFind.begin(),
        //                       newelemensToFind.end());
      }
      // printf("x: %d\n", x);
      // printf("subArrays: %d\n", subArrays);
      // printf("size of elementsToFind: %zu\n", elementsToFind.size());
      // printf("found: %d\n", found);
    }
    // for (int i = 0; i < newelemensToFind.size(); i++) {
    //   printf("elementsToFind: %d\n", *next(newelemensToFind.begin(), i));
    // }
    printf("%d\n", subArrays);
  }
}
