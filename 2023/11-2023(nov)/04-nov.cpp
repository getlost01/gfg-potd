//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int transitionPoint(int arr[], int n) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            
            if (arr[m] < 1)
                l = m + 1;
            else
                r = m;
        }
        
        return arr[l] ? l : -1;
    }
};


//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends