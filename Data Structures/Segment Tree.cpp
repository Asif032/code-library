#include<bits/stdc++.h>
using namespace std;

struct item {
  long long sum;
};

struct segtree {
  int n;
  vector<item> t;
  item NEUTRAL_ELEMENT = {0};     // modify this

  item merge(item lc, item rc) {   // modify this
    return {lc.sum + rc.sum};
  }
  item single(int v) {   // modify this
    return {v};
  }
  void init(int N) {
    n = N;
    t.resize(4 * N + 5);
  }
  void build(vector<int>& a, int x, int lx, int rx) {
    if (lx == rx) {
      t[x] = single(a[lx]);
      return;
    }
    int mid = (lx + rx) >> 1;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid + 1, rx);
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }
  void build(vector<int>& a) {
    build(a, 0, 0, n - 1);
  }
  void update(int i, int v, int x, int lx, int rx) {
    if (lx == rx) {
      t[x] = single(v);
      return;
    }
    int mid = (lx + rx) >> 1;
    if (i <= mid) {
      update(i, v, 2 * x + 1, lx, mid);
    } else {
      update(i, v, 2 * x + 2, mid + 1, rx);
    }
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }
  void update(int i, int v) {
    update(i, v, 0, 0, n - 1);
  }
  item query(int l, int r, int x, int lx, int rx) {
    if (lx > r || rx < l) return NEUTRAL_ELEMENT;
    if (lx >= l && rx <= r) return t[x];
    int mid = (lx + rx) >> 1;
    item lc = query(l, r, 2 * x + 1, lx, mid);
    item rc = query(l, r, 2 * x + 2, mid + 1, rx);
    return merge(lc, rc);
  }
  item query(int l, int r) {
    return query(l, r, 0, 0, n - 1);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    segtree st;
    st.init(n);
    st.build(a);
    while(q--) {
      
    }
  }
  return 0;
}