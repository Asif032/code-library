#include<bits/stdc++.h>
using namespace std;

int a[200005], seg[4 * 200005];

void build(int ind, int low, int high) {
  if(low == high) {
    seg[ind] = a[low];
    return;
  }
  int mid = (low + high) / 2;
  build(2 * ind + 1, low, mid);
  build(2 * ind + 2, mid + 1, high);
  seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r) {
  if(low >= l && high <= r) {
    return seg[ind];        
  }
  if(low > r || high < l) return INT_MAX;
  int mid = (low + high) / 2;
  int left = query(2 * ind + 1, low, mid, l, r);
  int right = query(2 * ind + 2, mid + 1, high, l, r);
  return min(left, right);
}

void update(int ind, int low, int high, int p, int x) {
  if(low == high) {
    seg[ind] = x;
    return;
  }
  int mid = (low + high) / 2;
  if(p <= mid && p >= low) update(2 * ind + 1, low, mid, p, x);
  else update(2 * ind + 2, mid + 1, high, p, x);
  seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q, l, r, type, p, x;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> a[i];    
  }
  build(0, 0, n - 1);
  // cin >> q;
  while(q--) {
    cin >> type;
    if(type == 1) {
        cin >> p >> x;
        p--;           // converting p to 0 based index
        update(0, 0, n - 1, p, x);
    } else {
        cin >> l >> r;
        l--;r--;      // // converting l and r to 0 based index
        cout << query(0, 0, n - 1, l, r) << '\n';
    }
  }
  return 0;
}