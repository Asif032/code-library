#include<bits/stdc++.h>
using namespace std;

void makeTable(vector<vector<int>> &dp, vector<int> v, int n, int p) {
  for(int i = 0; i < n; i++) {
    dp[0].push_back(v[i]);          
  }
  for(int i = 1; i <= p; i++) {
    for(int j = 0; j + (1 << i) - 1 < n; j++) {  
      int k = 1 << (i - 1);
      dp[i].push_back(min(dp[i-1][j], dp[i-1][j+k]));
    }
  }
}

int main() {
	int n, q, l, r;
	cin >> n >> q;
	vector<int> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int p = log2(n);
  vector<vector<int>> dp(p+1);
  makeTable(dp, v, n, p);
  cin >> q;
  while(q--){
  	cin >> l >> r;
  	l--; r--;
  	int p = log2(r - l + 1);
  	int k = 1 << p;
		cout << min(dp[p][l], dp[p][r-k+1]) << '\n';
   }
    return 0;
}