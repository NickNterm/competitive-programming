#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int permutations = 0;
  int N = 0;
  vector<int> PermA;
  list<int> PermB;
  // vector<int> PermB;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int tmp;
    scanf("%d", &tmp);
    PermA.push_back(tmp);
  }
  for (int i = 0; i < N; i++) {
    int tmp;
    scanf("%d", &tmp);
    PermB.push_back(tmp);
  }

  auto pointer = PermB.begin();
  auto pointerPrev = PermB.begin();

  for (int i = 0; i < N; i++) {
    // printf("Pointer: %d element %d\n", *pointer, PermA[i]);

    // printf("-------------- %d\n", permutations);
    // for (auto a : PermB) {
    //   printf("%d ", a);
    // }
    // printf("\n");
    // for (int a = 0; a < N; a++) {
    //   printf("%d ", PermA[a]);
    // }
    // printf("\n");
    // printf("--------------\n");
    if (*pointer != PermA[i]) {
      auto pos = find(PermB.begin(), PermB.end(), PermA[i]);
      permutations += distance(PermB.begin(), pos) - i;
      PermB.insert(pointerPrev, *pos);
      PermB.erase(pos);
    }
    pointerPrev = next(PermB.begin(), i);
    pointer = pointerPrev++;
  }
  printf("%d\n", permutations);
}
