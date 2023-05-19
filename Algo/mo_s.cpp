#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 1e6 + 5;
const int BLOCK_SIZE = 400;
int res, a[N], cnt[M];

struct Query {
  int l, r, id;
  bool operator < (const Query other) const {
    if (l / BLOCK_SIZE != other.l / BLOCK_SIZE) {
      return l < other.l;
    }
    return (l / BLOCK_SIZE & 1) ? r < other.r : r > other.r;
  }
};

void add(int i) {
  cnt[a[i]]++;
  if (cnt[a[i]] == 1) res++;
}

void remove(int i) {
  cnt[a[i]]--;
  if (cnt[a[i]] == 0) res--;
}

int get_ans() {
  return res;
}

vector<int> mo_s(vector<Query> &Q) {
  sort(Q.begin(), Q.end());
  vector<int> ans(Q.size());
  int L = 0;
  int R = -1;
  for (Query q : Q) {
    while (L < q.l) remove(L++);
    while (L > q.l) add(--L);
    while (R < q.r) add(++R);
    while (R > q.r) remove(R--);
    ans[q.id] = get_ans();
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  vector<Query> Q(q);
  for (int i = 0; i < q; i++) {
    cin >> Q[i].l >> Q[i].r;
    Q[i].l--; Q[i].r--;
    Q[i].id = i;
  }
  vector<int> ans = mo_s(Q);
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}