#include<bits/stdc++.h>
using namespace std;

struct segtree {
  int n;
  vector<long long> t, lazy;
  long long NEUTRAL_ELEMENT = 0;  // modify this

  long long merge(long long lc, long long rc) {   // modify this
    return lc + rc;
  }
  long long single(int v) {   // modify this
    return v;
  }
  void propagate(int x, int lx, int rx) {   // modify this
    if (lazy[x] == 0) return;
    t[x] = t[x] + (rx - lx + 1) * lazy[x];
    if (lx != rx) {
      lazy[2 * x + 1] += lazy[x];
      lazy[2 * x + 2] += lazy[x];
    }
    lazy[x] = 0;
  }
  void init(int size) {
    n = size;
    t.resize(4 * size + 5);
    lazy.resize(4 * size + 5);
  }
  void build(vector<int>& a, int x, int lx, int rx) {
    lazy[x] = 0;
    if (lx == rx) {
      t[x] = single(a[lx]);
      return;
    }
    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid + 1, rx);
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }
  void build(vector<int>& a) {
    build(a, 0, 0, a.size() - 1);
  }
  void update(int l, int r, int v, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (lx > r || rx < l) return;
    if (lx >= l && rx <= r) {
      lazy[x] = v;
      propagate(x, lx, rx);
      return;
    }
    int mid = (lx + rx) / 2;
    update(l, r, v, 2 * x + 1, lx, mid);
    update(l, r, v, 2 * x + 2, mid + 1, rx);
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }
  void update(int l, int r, int v) {
    update(l, r, v, 0, 0, n - 1); 
  }
  long long query(int l, int r, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (lx > r || rx < l) return NEUTRAL_ELEMENT;
    if (lx >= l && rx <= r) return t[x];
    int mid = (lx + rx) / 2;
    long long lc = query(l, r, 2 * x + 1, lx, mid);
    long long rc = query(l, r, 2 * x + 2, mid + 1, rx);
    return merge(lc, rc);
  }
  long long query(int l, int r) {
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