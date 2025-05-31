#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

class Nest {
public:
  int id;
  int type;
  long long x, y, r;
  long long x1, y1, x2, y2;
  long long bbx1, bby1, bbx2, bby2;

  Nest(int pid, long long px1, long long py1, long long px2, long long py2) {
    id = pid;
    x1 = px1;
    x2 = px2;
    y1 = py1;
    y2 = py2;
    type = 1;
    bbx1 = px1;
    bbx2 = px2;
    bby1 = py1;
    bby2 = py2;
  }

  Nest(int pid, long long px, long long py, long long pr) {
    id = pid;
    x = px;
    y = py;
    r = pr;
    bbx1 = px - r;
    bbx2 = px + r;
    bby1 = py - r;
    bby2 = py + r;
    type = 0;
  }
};

bool compByX(Nest a, Nest b) {
  return a.bbx1 < b.bbx1; // it sorts in ascending order
}

int dfs(int node, vector<vector<int>> &adjlist, vector<int> &memo) {
  if (memo[node] != -1)
    return memo[node];

  int level = 1;
  for (int neighbor : adjlist[node]) {
    level = max(level, dfs(neighbor, adjlist, memo) + 1);
  }
  return memo[node] = level;
}

int longestPath(vector<vector<int>> &adjlist) {
  int n = adjlist.size();
  vector<int> memo(n, -1);
  int result = 0;

  for (int i = 0; i < n; i++) {
    result = max(result, dfs(i, adjlist, memo));
  }
  return result;
}

bool shouldAdd(Nest a, Nest b) {
  Nest atemp = a;

  if (atemp.bbx1 <= b.bbx1 && atemp.bbx2 >= b.bbx2 && atemp.bby1 <= b.bby1 &&
      atemp.bby2 >= b.bby2) {
    if (a.type == 1 && b.type == 1) {
      return true;
    } else if (atemp.type == 1 && b.type == 0) {
      return true;
    } else if (atemp.type == 0 && b.type == 0) {
      if ((b.x - atemp.x) * (b.x - atemp.x) +
              (b.y - atemp.y) * (b.y - atemp.y) <=
          atemp.r * atemp.r) {
        return true;
      } else {
        return false;
      }
    } else {
      if (sqrt((b.x1 - atemp.x) * (b.x1 - atemp.x) +
               (b.y1 - atemp.y) * (b.y1 - atemp.y)) <= atemp.r + b.r &&
          (b.x2 - atemp.x) * (b.x2 - atemp.x) * (b.y2 - atemp.y) *
                  (b.y2 - atemp.y) <=
              atemp.r * atemp.r) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);

  vector<Nest> nests;
  vector<vector<int>> adjlist;

  for (int i = 0; i < n; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int x, y, r;
      scanf("%d %d %d", &x, &y, &r);
      nests.push_back(Nest(i, x, y, r));
    } else if (type == 0) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      nests.push_back(Nest(i, x1, y1, x2, y2));
    }
  }

  adjlist.resize(n);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      Nest a = nests[i];
      Nest b = nests[j];
      if (shouldAdd(a, b) && shouldAdd(b, a)) {
        adjlist[i].push_back(j);
      } else if (shouldAdd(a, b)) {
        adjlist[i].push_back(j);
      } else if (shouldAdd(b, a)) {
        adjlist[j].push_back(i);
      }
    }
  }
  // for (int i = 0; i < adjlist.size(); i++) {
  //   printf("%ld: ", i);
  //   for (int j = 0; j < adjlist[i].size(); j++) {
  //     printf("%ld ", adjlist[i][j]);
  //   }
  //   printf("\n");
  // }

  int maximum = longestPath(adjlist);

  printf("%ld\n", maximum);
  return 0;
}
