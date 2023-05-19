struct Compare {
  bool operator() (pair<int, int> below, pair<int, int> above) {
    if (below.first == above.first) {
      return below.second > above.second;
    }
    return below.first < above.first;
  }
};