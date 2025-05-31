#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

template <typename T> class SegmentTree {
private:
  vector<T> tree;
  vector<T> arr;
  int n;

  int left(int node) { return 2 * node + 1; }
  int right(int node) { return 2 * node + 2; }
  int mid(int l, int r) { return l + (r - l) / 2; }

  void build(int node, int start, int end) {
    if (start == end) {
      tree[node] = arr[start];
      return;
    }
    // Calculate the middle index
    int m = mid(start, end);
    // Recursively build the left and right children
    build(left(node), start, m);
    build(right(node), m + 1, end);
    // Internal node will store the max of the two
    // children
    tree[node] = max(tree[left(node)], tree[right(node)]);
  }

  // Function to update the value at a specific index in
  // the segment tree
  void update(int node, int start, int end, int idx, T val) {
    // If the current node represents a single element,
    // update it
    if (start == end) {
      arr[idx] = val;
      tree[node] = val;
      return;
    }
    // Calculate the middle index
    int m = mid(start, end);
    // Recursively update the left or right child
    if (idx <= m)
      update(left(node), start, m, idx, val);
    else
      update(right(node), m + 1, end, idx, val);
    // Internal node will store the  max of the two
    // children
    tree[node] = max(tree[left(node)], tree[right(node)]);
  }

  void updateand(int node, int start, int end, int idx, T x, T l) {
    // If the current node represents a single element,
    // update it
    if (start == end) {
      arr[idx] = arr[idx] ^ (x + idx - l - 1);
      tree[node] = arr[idx] ^ (x + idx - l - 1);
      return;
    }
    // Calculate the middle index
    int m = mid(start, end);
    // Recursively update the left or right child
    if (idx <= m)
      updateand(left(node), start, m, idx, x, l);
    else
      updateand(right(node), m + 1, end, idx, x, l);
    // Internal node will store the max of the two
    // children
    tree[node] = max(tree[left(node)], tree[right(node)]);
  }

  // Function to query the  max value in a given range
  T query(int node, int start, int end, int l, int r) {
    // If the current node's range is completely outside
    // the query range
    if (r < start || end < l)
      return INT_MIN;
    // If the current node's range is completely inside
    // the query range
    if (l <= start && end <= r)
      return tree[node];
    // Calculate the middle index
    int m = mid(start, end);
    // Recursively query the left and right children and
    // combine the results
    T left_max = query(left(node), start, m, l, r);
    T right_max = query(right(node), m + 1, end, l, r);
    printf("LMAX %d RMAX %d\n", left_max, right_max);
    return max(left_max, right_max);
  }

public:
  // Constructor to initialize the segment tree with the
  // input array
  SegmentTree(const vector<T> &a) : arr(a), n(a.size()) {
    // Resize the tree to accommodate the segment tree
    // nodes
    tree.resize(4 * n);
    // Build the segment tree
    build(0, 0, n - 1);
  }

  // Public function to update the value at a specific
  // index
  void update(int idx, T val) { update(0, 0, n - 1, idx, val); }

  // Public function to query the minimum value in a given
  // range
  T query(int l, int r) { return query(0, 0, n, l, r); }

  // A[i] ⊕ (x + i − l)
  void action2(int l, int r, int x) {
    for (int i = 0; i < arr.size(); i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = l; i < r; i++) {
      updateand(0, 0, n - 1, i, x, l);
    }
    for (int i = 0; i < arr.size(); i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
};

int main() {
  int n, m;
  vector<int> list;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    list.push_back(a);
  }
  SegmentTree<int> st(list);

  for (int i = 0; i < m; i++) {
    int action;
    scanf("%d", &action);
    if (action == 1) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      st.action2(l - 1, r, x);
    } else if (action == 2) {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%d\n", st.query(l - 1, r - 1));
    }
  }
}
