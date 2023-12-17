//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findMaxSum(int *arr, int n) {
        int lastPrev = 0;
        int prev = arr[0];
        int curr = 0;

        for (int i = 1; i < n; ++i) {
            curr = max(prev, arr[i] + lastPrev);
            lastPrev = prev;
            prev = curr;
        }

        return max(lastPrev, prev);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends