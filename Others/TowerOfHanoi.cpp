#include<iostream>
using namespace std;

void TOH(int n, int A, int B, int C) {

	if(n == 0) return;

	TOH(n - 1, A, C, B);
	cout << "Move 1 disc from tower "<< A <<" to tower "<< C <<"\n";
	TOH(n - 1, B, A, C);
}
int main() {

	int n;
	cin >> n;
	TOH(n, 1, 2, 3);

	return 0;
}