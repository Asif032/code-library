struct cmp {
  template <typename T1, typename T2>
  bool operator() (const pair<T1, T2>& x, const pair<T1, T2>& y) const {
    if (x.first == y.first) {
      return x.second > y.second;
    }
    return x.first < y.first;
  }
};