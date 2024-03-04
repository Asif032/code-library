#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int>& p, vector<int>& c) {
  int n = p.size();
  vector<int> cnt(n);
  for (auto x : c) {
    cnt[x]++;
  }
  vector<int> p_new(n);
  vector<int> pos(n);
  pos[0] = 0;
  for (int i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }
  for (auto x : p) {
    int key = c[x];
    p_new[pos[key]++] = x;
  }
  p = p_new;
}

struct SuffixArray {
  vector<int> p, c, lcp;
  vector<pair<char, int>> a;
  string s;
  int n;
  SuffixArray(string t) : s(t) {
    s += "$";
    n = s.size();
    p.resize(n);
    c.resize(n);
    a.resize(n);
    lcp.resize(n);
    for (int i = 0; i < n; i++) {
      a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      p[i] = a[i].second;
    }
    for (int i = 0; i < n; i++) {
      p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (a[i].first == a[i - 1].first) {
        c[p[i]] = c[p[i - 1]];
      } else {
        c[p[i]] = c[p[i - 1]] + 1;
      }
    }
    int k = 0;
    while ((1 << k) < n) {
      for (int i = 0; i < n; i++) {
        p[i] = (p[i] - (1 << k) + n) % n;
      }
      count_sort(p, c);
      vector<int> c_new(n);
      c_new[p[0]] = 0;
      for (int i = 1; i < n; i++) {
        pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
        pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
        if (cur == prev) {
          c_new[p[i]] = c_new[p[i - 1]];
        } else {
          c_new[p[i]] = c_new[p[i - 1]] + 1;
        }
      }
      c = c_new;
      k++;
    }
    k = 0;
    for (int i = 0; i < n - 1; i++) {
      int pi = c[i];
      int j = p[pi - 1];
      while (s[i + k] == s[j + k]) k++;
      lcp[pi] = k;
      k = max(k - 1, 0);
    }
  }
  void print() {
    for (int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
  vector<int> get() {
    return p;
  }
  int cmp (int x, string t) {
    int m = t.size();
    int l = n - x;
    for (int i = 0; i < min(m, l); i++) {
      if (s[i + x] < t[i]) {
        return -1;
      } else if (s[i + x] > t[i]) {
        return 1;
      }
    }
    return l < m ? -1 : 0;
  }
  int count(string t) {
    int i = -1, j = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int status = cmp(p[mid], t);
      if (status == -1) {
        l = mid + 1;
      } else if (status == 1) {
        r = mid - 1;
      } else {
        i = mid;
        r = mid - 1;
      }
    }
    if (i == -1) {
      return 0;
    }
    l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int status = cmp(p[mid], t);
      if (status == -1) {
        l = mid + 1;
      } else if (status == 1) {
        r = mid - 1;
      } else {
        j = mid;
        l = mid + 1;
      }
    }
    return j - i + 1;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  SuffixArray sa(s);
  return 0;
}