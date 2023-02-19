#include<bits/stdc++.h>
using namespace std;

long long maxHistogram(vector<int> &input) {
	long long area, maxArea = 0;
	stack<> st;
	long long i;
	for(i = 0; i < input.size(); ) {
		if(st.empty() || input[st.top()] <= input[i]) {
			st.push(i++);
		} else {
			int t = st.top(); 
			st.pop();
			if(st.empty()) {
				area = input[t] * i;
			} else {
				area = input[t] * (i - st.top() - 1);
			}
			maxArea = max(maxArea, area);
		}
	}
	while(!st.empty()) {
		int t = st.top();
		st.pop();
		if(st.empty()) {
			area = input[t] * i;
		} else {
			area = input[t] * (i - st.top() - 1);
		}
		maxArea = max(maxArea, area);
	}
	return maxArea;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> input(n);
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	cout << maxHistogram(input) << '\n';
	return 0;
}