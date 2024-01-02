//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long int> pre(n, 0);
        pre[0] = a[0];

        for (int i = 1; i < n; ++i)
            pre[i] = pre[i - 1] + a[i];

        long long int sum = pre[k - 1];
        long long int ans = sum;

        for (int i = k; i < n; i++) 
        {
            long long int cur = pre[i] - pre[i - k];
            sum = max(cur, sum + a[i]);
            ans = max(ans, sum);
        }

        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends