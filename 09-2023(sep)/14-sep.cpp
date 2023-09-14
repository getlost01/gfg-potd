//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int arr[], int n, int i, int sum, vector<vector<int>>& dp) {
        if (sum == 0)
            return 1;

        if (i >= n)
            return 0;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        long long t = 0;
        long long nt = solve(arr, n, i + 1, sum, dp);

        if (sum >= arr[i])
            t = solve(arr, n, i + 1, sum - arr[i], dp);

        return dp[i][sum] = (t + nt) % mod;
    }

    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        sort(arr, arr + n);
        int out = solve(arr, n, 0, sum, dp);
        return out;
    }
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends