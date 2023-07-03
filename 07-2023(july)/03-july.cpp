//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int maxDiff = 0;
        int i = 0, j = n - 1;
        int lastJ = 0;

        while (i < j) {
            if (arr[i] <= arr[j]) {
                maxDiff = max(maxDiff, j - i);
                lastJ = j;
                j = n - 1;
                i++;
            }
            else if (j > lastJ) {
                j--;
            }
            else if (j <= lastJ) {
                j = n - 1;
                i++;
            }
        }
        return maxDiff;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends