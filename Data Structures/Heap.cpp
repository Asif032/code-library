#include<bits/stdc++.h>
using namespace std;

void createHeap(int* input, int* heap, int n) {

	for(int i = 1; i <= n; i++) {
		heap[i] = input[i - 1];
		int j = i;
		while(j / 2 > 0 && heap[j] > heap[j / 2]) {
			swap(heap[j], heap[j / 2]);
			j /= 2;
		} 
	}
}

void heapSort(int* heap, int n) {

	for(int i = n; i > 0; i--) {
		swap(heap[1], heap[i]);
        int j = 1;
		while(1) {
			if(2 * j <= i - 1 && heap[2 * j] > heap[j]) {
                swap(heap[j], heap[2 * j]);
                j = 2 * j;
            }
            else if(2 * j + 1 <= i - 1 && heap[2 * j + 1] > heap[j]) {
                swap(heap[j], heap[2 * j + 1]);
                j = 2 * j + 1;
            }
            else break;
		}
	}
}

void printHeap(int* a, int n) {

	for(int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {

	int n;
	cin >> n;
	int input[n], heap[n + 1];
	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}
	createHeap(input, heap, n);
	printHeap(heap, n);
    heapSort(heap, n);
    printHeap(heap, n);

	return 0;
}