#include<bits/stdc++.h>
using namespace std;

int search(vector<int> a, int l, int r, int x) {
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(a[mid] > x) {
      r = mid - 1;
    } else if(a[mid] < x) {
      l = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  vector<int> a{1, 2, 2, 3, 4, 5, 5};
  cout << search(a, 0, a.size() -1, 4);
  return 0;
}