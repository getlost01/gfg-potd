//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long sumBitDifferences(int arr[], int n) {
        long long out = 0;
        for(int i=0; i<32; ++i){
            long long one = 0;
            for(int j = 0; j < n; ++j)
                if((arr[j]&(1<<i))!=0)
                    ++one;
            long long zero = n - one;
            out += 2*one*zero;
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
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends