#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

vector<vector<ll>> mult(vector<vector<ll>> &A, vector<vector<ll>> &B) { 
  ll p = A.size(), q = B.size(), r = B[0].size();  // dimension of A -> (pq), B -> (qxr)
  vector<vector<ll>> res(p, vector<ll> (r));       // dimention of res -> (pxr)                   
  for (int i = 0; i < p; i++) {                     
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < q; k++) {
        res[i][j] += A[i][k] * B[k][j] % mod;
        res[i][j] %= mod;
      }
    }
  }
  return res;
}

vector<vector<ll>> power(vector<vector<ll>> &M, long long n) {
  ll N = M.size();
  vector<vector<ll>> I(N, vector<ll> (N));
  for (int i = 0; i < N; i++) I[i][i] = 1;
  while (n) {
    if (n & 1) I = mult(I, M);
    M = mult(M, M);
    n >>= 1;
  }
  return I;
}

ll nth_term(long long n) {
  if (n == 0) return 0;  // modify this
  vector<vector<ll>> M(2, vector<ll> (2));
  vector<vector<ll>> F(1, vector<ll> (1));
 // |F1 F2|
  F[0][0] = 0;     // F1
  F[0][1] = 1;     // F2
 // |A B| A = 0, B = coefficient of F(n - 2)
 // |C D| C = 1, D = coefficient of F(n - 1)
  M[0][0] = 0;     // A = 0
  M[1][0] = 1;     // B = 1
  M[0][1] = 2;     // modify this, M[0][1] = B = coefficient of F(n - 2)
  M[1][1] = 1;     // modify this, M[1][1] = D = coefficient of F(n - 1)
// |F1 F2| * |M| = |F2 F3|
// |F1 F2| * |M|^(n-1) = |Fn Fn+1|
  M = power(M, n - 1);
  F = mult(F, M);
  return F[0][0]; // F(n)
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    cout << "F(" << n << ") = ";
    cout << nth_term(n) << '\n';
  }
  return 0;
}