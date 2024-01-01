//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int out = 0;
        int i = 0, j = 0;
        long long currProd = 1;

        while (i < n && j < n) {
            currProd *= a[j];

            while (currProd >= k && i < j) {
                currProd /= a[i];
                i++;
            }
            
            if (currProd < k)
                out += j - i + 1;

            j++;
        }
        return out;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends