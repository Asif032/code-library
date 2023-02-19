#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> tree(200005);
int n;

void makeTree() {
    for (int i = 1; i <= n; i++) {
        int j = i + (i & -i);
        if (j <= n) tree[j] += tree[i];
    }
}

ll prefixSum(int i) {
    ll sum = 0;
    while (i) {
        sum += tree[i];
        i -= i & -i;
    }
    return sum;
}

ll sum(int i, int j) {
    return prefixSum(j) - prefixSum(i - 1);
}

void add(int i, int k) {
    while (i <= n) {
        tree[i] += k;
        i += i & -i;
    }
}

void update(int i, int k) {
    add(i , k - sum(i, i));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, l, r, type, k, p;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> tree[i];
    }
    makeTree();
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> p >> k;
            update(p, k);
        } else {
            cin >> l >> r;
            cout << sum(l, r) << '\n';
        }
    }
    return 0;
}