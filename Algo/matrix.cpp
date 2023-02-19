#include<iostream>
#include<vector>
using namespace std;

int r1, c1, r2, c2;

vector<vector<int>> multiplyMatrix(vector<vector<int>> &A, vector<vector<int>> &B) {

	int n = A.size(), m = B[0].size();

	vector<vector<int>> res(n, vector<int> (m));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < n; k++) {
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return res;
}

void print(vector<vector<int>> &A) {

	int n = A.size(), m = A[0].size();

	cout << "\nThe resulting matrix is : \n";

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}


void getMatrix() {

	cout << "Enter the number of rows of the first matrix : ";
	cin >> r1;
	cout << "Enter the number of columns of the first matrix : ";
	cin >> c1;
	cout << "Enter the elements of the "<< r1 <<" X "<< c1 <<" matrix : \n";

	vector<vector<int>> m1(r1, vector<int> (c1));

	for(int i = 0; i < r1; i++) {
		for(int j = 0; j < c1; j++) {
			cin >> m1[i][j];
		}
	}
	cout << "Enter the number of rows of the second matrix : ";
	cin >> r2;
	cout << "Enter the number of columns of the second matrix : ";
	cin >> c2;
	cout << "Enter the elements of the "<< r2 <<" X "<< c2 <<" matrix : \n";

	vector<vector<int>> m2(r2, vector<int> (c2));

	for(int i = 0; i < r2; i++) {
		for(int j = 0; j < c2; j++) {
			cin >> m2[i][j];
		}
	}
	if(c1 != r2) {
		cout << "Invalid input, try again !\n";
		cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix\n";
		getMatrix();
	} else {
		vector<vector<int>> res = multiplyMatrix(m1, m2);
		print(res);
	}
}

int main() {

	getMatrix();
	
	return 0;
}