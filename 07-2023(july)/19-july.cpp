//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    int check(int i, int j, int n, string &A, string &rev, vector<vector<int>>& dp){
        if(i == n || j == n)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(A[i] == rev[j]){
            dp[i][j] = 1 + check(i+1,j+1,n,A,rev,dp);
        }
        dp[i][j] = max(dp[i][j], check(i,j+1,n,A,rev,dp));
        dp[i][j] = max(dp[i][j], check(i+1,j,n,A,rev,dp));
    
        return dp[i][j];
    }
    int longestPalinSubseq(string A) {
        int n = A.size();
        string rev = A;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return check(0,0,n,A,rev,dp);
    }
};


//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends