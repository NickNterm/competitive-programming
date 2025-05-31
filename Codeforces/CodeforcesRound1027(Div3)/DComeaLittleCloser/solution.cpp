#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector<pair<long long, long long>> v;
    long long minx = LONG_MAX;
    long long miny = LONG_MAX;
    long long maxx = -1;
    long long maxy = -1;
    for (int i = 0; i < n; i++) {
      long long a, b;
      scanf("%llu %llu", &a, &b);
      v.push_back({a, b});
      if (a <= minx) {
        minx = a;
      }
      if (b <= miny) {
        miny = b;
      }
      if (a >= maxx) {
        maxx = a;
      }
      if (b >= maxy) {
        maxy = b;
      }
    }
    vector<pair<long long, long long>> tperim;
    if (n == 1) {
      printf("1\n");
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (v[i].first == minx || v[i].first == maxx || v[i].second == miny ||
          v[i].second == maxy) {
        tperim.push_back(v[i]);
      }
    }
    long long lowerCost = LLONG_MAX;
    vector<pair<long long, long long>> perim;
    sort(tperim.begin(), tperim.end(),
         [](const pair<long long, long long> &a,
            const pair<long long, long long> &b) {
           if (a.first == b.first) {
             return a.second < b.second;
           }
           return a.first < b.first;
         });
    perim.push_back(tperim[0]);
    perim.push_back(tperim[tperim.size() - 1]);

    sort(tperim.begin(), tperim.end(),
         [](const pair<long long, long long> &a,
            const pair<long long, long long> &b) {
           if (a.second == b.second) {
             return a.first < b.first;
           }
           return a.second < b.second;
         });
    perim.push_back(tperim[0]);
    perim.push_back(tperim[tperim.size() - 1]);
    for (auto &p : perim) {
      v.erase(find(v.begin(), v.end(), p));
      long long nminx = LLONG_MAX;
      long long nminy = LLONG_MAX;
      long long nmaxx = -1;
      long long nmaxy = -1;
      for (auto &q : v) {
        // printf("Checking point (%ld, %ld)\n", q.first, q.second);
        if (q.first <= nminx) {
          nminx = q.first;
        }
        if (q.second <= nminy) {
          nminy = q.second;
        }
        if (q.first >= nmaxx) {
          nmaxx = q.first;
        }
        if (q.second >= nmaxy) {
          nmaxy = q.second;
        }
      }

      long long area = (nmaxx - nminx + 1) * (nmaxy - nminy + 1);
      // printf("Area: %lld\n", area);
      if (area == v.size()) {
        // printf("Area is equal to number of points: %lld\n", area);
        area += min(nmaxx - nminx + 1, nmaxy - nminy + 1);
      }
      lowerCost = min(lowerCost, area);
      v.push_back(p);
    }
    printf("%lld\n", lowerCost);
  }
}
