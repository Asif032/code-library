#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long t[4 * N], lazy[4 * N];
int a[N];

void propagate(int x, int lx, int rx) {   // modify this
  if (lazy[x] == 0) return;
  t[x] = t[x] + (rx - lx + 1) * lazy[x];
  if (lx != rx) {
    lazy[2 * x + 1] += lazy[x];
    lazy[2 * x + 2] += lazy[x];
  }
  lazy[x] = 0;
}

void build(int x, int lx, int rx) {
  if (lx == rx) {
    t[x] = a[lx];
    return;
  }
  int mid = (lx + rx) / 2;
  build(2 * x + 1, lx, mid);
  build(2 * x + 2, mid + 1, rx);
  t[x] = t[2 * x + 1] + t[2 * x + 2];   // modify this
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
  t[x] = t[2 * x + 1] + t[2 * x + 2];   // modify this
}

long long query(int l, int r, int x, int lx, int rx) {
  propagate(x, lx, rx);
  if (lx > r || rx < l) return 0;
  if (lx >= l && rx <= r) return t[x];
  int mid = (lx + rx) / 2;
  long long lc = query(l, r, 2 * x + 1, lx, mid);
  long long rc = query(l, r, 2 * x + 2, mid + 1, rx);
  return lc + rc;       // modify this
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  return 0;
}