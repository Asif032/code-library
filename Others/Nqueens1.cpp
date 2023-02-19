#include<bits/stdc++.h>
using namespace std;

int MAX = 200005, n;
vector<bool> col(MAX), diag1(MAX), diag2(MAX);
vector<int> c(MAX);

void printsolution() {

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			cout << (c[i] == j ? 1 : 0);
			if(j < n - 1) cout << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool Nqueens(int row) {

	if(row == n) {
		// printsolution();
		return true;
	}
	for(int i = 0; i < n; i++) {
		if(col[i] || diag1[i + row] || diag2[i - row + n - 1]) continue;
		col[i] = diag1[i + row] = diag2[i - row + n - 1] = 1;
		c[row] = i;
		if(Nqueens(row + 1)) return true;
		col[i] = diag1[i + row] = diag2[i - row + n - 1] = 0;
	}
	return false;
}


int main() {

	cin >> n;

	if(Nqueens(0)) {
		printsolution();
	} else {
		cout << "Not possible" << '\n';
	}
	return 0;
}