#include <bits/stdc++.h>
#include <cstdio>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> grid;
  set<tuple<int, int, int, int>> rects;

  for (int i = 0; i < n; i++) {
    grid.push_back(vector<int>());
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d", a);
      grid[i].push_back(a);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
      }
    }
  }
}

void dfs(vector<vector<int>> &grid, int x, int y, int n, int m,
         set<tuple<int, int, int, int>> &rect) {
  for (int i = x; i < n; i++) {
    for (int j = y; j < m; j++) {
    }
  }
}
