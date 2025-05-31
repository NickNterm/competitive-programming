#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

bool isPoliceOrWall(char c) {
  if (c == 'v' || c == '>' || c == '<' || c == '^' || c == '#') {
    return true;
  }
  return false;
}

vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool dfs(vector<vector<char>> &grid, int x, int y) {

  if (grid[x][y] == 'H') {
    return true;
  }
  grid[x][y] = '@';

  bool found = false;
  for (auto dir : directions) {
    int ni = x + dir.first;
    int nj = y + dir.second;
    if (ni >= grid.size() || ni < 0) {
      continue;
    }
    if (nj >= grid[0].size() || nj < 0) {
      continue;
    }
    char nextC = grid[x + dir.first][y + dir.second];
    if (nextC == '.' || nextC == 'H') {
      found = found || dfs(grid, x + dir.first, y + dir.second);
    }
    if (found) {
      break;
    }
  }
  return found;
}

int main() {
  int n, m, d;
  int sx, sy, ex, ey;

  scanf("%d %d %d", &n, &m, &d);
  vector<vector<char>> grid;
  grid.resize(n);
  bool hidden = false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      scanf("%c", &c);
      if (c == '\n') {
        j--;
        continue;
      }
      if (c == 'F') {
        sx = i;
        sy = j;
        c = 'F';
      } else if (c == 'H') {
        ex = i;
        ey = j;
        c = 'H';
      }

      grid[i].push_back(c);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c = grid[i][j];
      if (c == '>') {
        for (int a = j + 1; a < m; a++) {
          if (a > j + d)
            break;
          if (!isPoliceOrWall(grid[i][a])) {
            if (grid[i][a] == 'F' || grid[i][a] == 'H') {
              hidden = true;
            }
            grid[i][a] = '*';
          } else {
            break;
          }
        }
      } else if (c == '<') {
        for (int a = j - 1; a >= 0; a--) {
          if (a < j - d)
            break;
          if (!isPoliceOrWall(grid[i][a])) {
            if (grid[i][a] == 'F' || grid[i][a] == 'H') {
              hidden = true;
            }
            grid[i][a] = '*';
          } else {
            break;
          }
        }
      } else if (c == '^') {
        for (int a = i - 1; a >= 0; a--) {
          if (a < i - d)
            break;
          if (!isPoliceOrWall(grid[a][j])) {
            if (grid[a][j] == 'F' || grid[a][j] == 'H') {
              hidden = true;
            }
            grid[a][j] = '*';
          } else {
            break;
          }
        }
      } else if (c == 'v') {
        for (int a = i + 1; a < n; a++) {
          if (a > i + d)
            break;
          if (!isPoliceOrWall(grid[a][j])) {
            if (grid[a][j] == 'F' || grid[a][j] == 'H') {
              hidden = true;
            }
            grid[a][j] = '*';
          } else {
            break;
          }
        }
      }
    }
  }

  if (hidden) {
    printf("NO\n");
    return 0;
  }
  if (dfs(grid, sx, sy)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}
