//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
public:
    int maxIndexDiff(int arr[], int n) {
        int maxDiff = 0;
        vector<int> maxJ(n);
        
        for (int i = 0; i < n; i++)
            maxJ[i] = i;
            
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] <= arr[i])
                    maxJ[i] = j;
                
                if (maxJ[j] == j) {
                    if (arr[j] > arr[i])
                        break;
                }
                else if (arr[maxJ[j]] <= arr[i])
                    j = maxJ[j] + 1;
            }
            
            maxDiff = max(maxDiff, i - maxJ[i]);
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