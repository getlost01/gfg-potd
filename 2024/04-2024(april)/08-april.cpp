//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<vector<long long>> dp;
    
    long long solve(int arr[], int i, int j, int& n) {
        if (i >= n || j < 0 || j - i + 1 <= 0)
            return 0;
            
        if (dp[i][j] != -1)
            return dp[i][j];
        
        long long d1, d2;
        d1 = arr[i] + min(solve(arr, i + 2, j, n), solve(arr, i + 1, j - 1, n));
        d2 = arr[j] + min(solve(arr, i + 1, j - 1, n), solve(arr, i, j - 2, n));
        return dp[i][j] = max(d1, d2);
    }
    
    long long maximumAmount(int n, int arr[]) {
        dp = vector<vector<long long>>(1001, vector<long long>(1001, -1));
        return solve(arr, 0, n - 1, n);
    }
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends