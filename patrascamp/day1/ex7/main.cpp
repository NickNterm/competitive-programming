#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

template <typename T> class SegmentTree {
private:
  // Segment tree to store the minimums
  vector<T> tree;
  // Input array
  vector<T> arr;
  // Size of the input array
  int n;

  // Helper function to get the left child of a node
  int left(int node) { return 2 * node + 1; }

  // Helper function to get the right child of a node
  int right(int node) { return 2 * node + 2; }

  // Helper function to calculate the middle index
  int mid(int l, int r) { return l + (r - l) / 2; }

  // Function to build the segment tree
  void build(int node, int start, int end) {
    // If the current node represents a single element,
    // store it in the tree
    if (start == end) {
      tree[node] = arr[start];
      return;
    }
    // Calculate the middle index
    int m = mid(start, end);
    // Recursively build the left and right children
    build(left(node), start, m);
    build(right(node), m + 1, end);
    // Internal node will store the minimum of the two
    // children
    tree[node] = min(tree[left(node)], tree[right(node)]);
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
    // Internal node will store the minimum of the two
    // children
    tree[node] = min(tree[left(node)], tree[right(node)]);
  }

  // Function to query the minimum value in a given range
  T query(int node, int start, int end, int l, int r) {
    // If the current node's range is completely outside
    // the query range
    if (r < start || end < l)
      return INT_MAX;
    // If the current node's range is completely inside
    // the query range
    if (l <= start && end <= r)
      return tree[node];
    // Calculate the middle index
    int m = mid(start, end);
    // Recursively query the left and right children and
    // combine the results
    T left_min = query(left(node), start, m, l, r);
    T right_min = query(right(node), m + 1, end, l, r);
    return min(left_min, right_min);
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

  void apply_and(int l, int r, int x, vector<int> &arr) {
    for (int i = l; i <= r; ++i) {
      arr[i] &= x;
      update(i, arr[i]);
    }
  }

  // Public function to query the minimum value in a given
  // range
  T query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> list;

  for (int i = 0; i < n; i++) {
    int l;
    scanf("%d ", &l);
    list.push_back(l);
  }

  SegmentTree<int> stree = SegmentTree<int>(list);

  int actions;
  scanf("%d", &actions);

  for (int i = 0; i < actions; i++) {
    int c;
    scanf("%d ", &c);
    if (c == 1) {
      int p;
      int x;
      scanf("%d %d", &p, &x);
      list[p - 1] = x;
      stree.update(p - 1, x);
    } else if (c == 2) {
      int l;
      int r;
      int x;
      scanf("%d %d %d", &l, &r, &x);
      for (int a = l - 1; a < r; a++) {
        stree.update(a, list[a] & x);
      }
    } else if (c == 3) {
      int l;
      int r;
      scanf("%d %d", &l, &r);
      int sum = 0;
      for (int a = l - 1; a < r; a++) {
        sum += stree.query(a, a);
      }
      printf("%d\n", sum);
    }
  }
}
