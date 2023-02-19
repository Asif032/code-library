#include<bits/stdc++.h>
using namespace std;

minSubarray(int* a, int n, int targetSum)
{
    int size = 1e9;
    int winStart = 0;
    int currentSum = 0;

    for(int winEnd = 0; winEnd < n; winEnd++){
        currentSum += a[winEnd];
        
        while(currentSum >= targetSum){
            size = min(size, winEnd - winStart + 1);
            currentSum -= a[winStart];
            winStart++;
        }
    }
    return size == 1e9 ? 0 : size;
}
/*
pair<int, int> twoSum(int* a, int n, int targetSum)
{
    sort(a, a + n);

    int i = 0, j = n - 1;
    while(i < j){
        int currentSum = a[i] + a[j];
        if(currentSum > targetSum) j--;
        else if(currentSum < targetSum) i++;
        else return {a[i], a[j]};
    }
    return {-1, -1};
} */
int main()
{
    int a[] = {1, 3, 2, 8, 1, 1, 2, 3};
    int n = 8;
    int targetSum = 8;

  //  cout << minSubarray(a, n, targetSum);

    int b[] = {1, 4, 5, 6, 7, 8, 9, 9, 10};

  //  pair<int, int> p = twoSum(b, 9, 12);

  //  cout(p.first == -1 && )

    int arr[] = {2, 1, 3, 6, 4, 5, 2, 3, 6};

    stack<int> st;

    for(int i = 0; i < n; i++){   // nearest smallest element
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        cout << (st.empty() ? -1 : st.top()) << ' ';
        st.push(arr[i]); 
    }

    cout << '\n';

    deque<int> dq;
  //  int arr[] = {2, 1, 3, 6, 4, 5, 2, 3, 6};
    int k = 3;

    for(int i = 0; i < 9; i++){         // sliding window minimum

        while(!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
        dq.push_back(i);

        if(i >= k - 1){
            cout << arr[dq.front()] << ' ';
            if(dq.front() <= i - k + 1) dq.pop_front();
        }
    }

    cout << '\n';

    for(int i = 0; i < 9; i++){         // sliding window maximum

        while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);

        if(i >= k - 1){
            cout << arr[dq.front()] << ' ';
            if(dq.front() <= i - k + 1) dq.pop_front();
        }
    }

    cout << '\n';


    return 0;
}