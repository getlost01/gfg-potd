//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int LCS(string& X, string& Y, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        if (X[i] == Y[j])
            return dp[i][j] = 1 + LCS(X, Y, i - 1, j - 1, dp);

        return dp[i][j] = max(LCS(X, Y, i, j - 1, dp), LCS(X, Y, i - 1, j, dp));
    }

    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int lcs = LCS(X, Y, m - 1, n - 1, dp);
        return m + n - lcs;
    }
};


//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends