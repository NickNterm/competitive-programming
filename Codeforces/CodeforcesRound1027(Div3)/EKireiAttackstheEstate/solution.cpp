#include <bits/stdc++.h>

using namespace std;

long long maxThread(long long value, long long i, vector<long long> &dangers,
                    vector<vector<long long>> &adj, long long isPlus,
                    vector<long long> &visited) {
  int maxDanger = isPlus == 1 ? value + dangers[i] : value - dangers[i];
  if (i == 1) {
    return maxDanger; // reached root
  }
  for (int j : adj[i]) {
    if (visited[j] == 0) {
      visited[j] = 1;
      int danger =
          maxThread(maxDanger, j, dangers, adj, isPlus == 1 ? 0 : 1, visited);
      maxDanger = max(maxDanger, danger);
      visited[j] = 0; // backtrack
    }
  }
  return maxDanger;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    printf("Enter number of vertices: %d\n", n);
    vector<long long> dangers(n + 1, 0);
    dangers.push_back(0);
    vector<vector<long long>> adj(n + 1);
    for (int i = 0; i < n; i++) {
      long long a;
      scanf("%llu", &a);
      dangers.push_back(a);
    }
    for (int i = 0; i < n - 1; i++) {
      long long a, b;
      scanf("%llu %llu", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    // we need to go from the each vertex to root
    vector<long long> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      vector<long long> visited(n + 1, 0);
      visited[i] = 1; // mark current node as visited
      ans[i] = maxThread(dangers[i], i, dangers, adj, 1, visited);
    }
    for (int i = 1; i <= n; i++) {
      printf("%llu ", ans[i]);
    }
    printf("\n");
  }
}
