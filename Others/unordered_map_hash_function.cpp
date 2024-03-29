struct hash_pair {
template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);

    if (hash1 != hash2) {
      return hash1 ^ hash2;              
    }
     
    // If hash1 == hash2, their XOR is zero.
    return hash1;
  }
};