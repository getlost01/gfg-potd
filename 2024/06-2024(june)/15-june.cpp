//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n)
    {
        if (n == 1) return 10;
        vector<vector<int>> adj = {
            {0, 8},  
            {1, 2, 4}, 
            {2, 1, 3, 5},
            {3, 2, 6}, 
            {4, 1, 5, 7},
            {5, 2, 4, 6, 8}, 
            {6, 3, 5, 9}, 
            {7, 4, 8}, 
            {8, 5, 7, 9, 0}, 
            {9, 6, 8}  
        };

        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));


        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }

        // Fill the dp table
        for (int len = 2; len <= n; len++) {
            for (int digit = 0; digit < 10; digit++) {
                dp[len][digit] = 0;
                for (int neighbor : adj[digit]) {
                    dp[len][digit] += dp[len - 1][neighbor];
                }
            }
        }

        long long totalCount = 0;
        for (int digit = 0; digit < 10; digit++) {
            totalCount += dp[n][digit];
        }

        return totalCount;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
