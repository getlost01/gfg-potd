//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool solve(int i, int& n, int sum, int coins[], vector<unordered_map<int,bool>>& dp){
        if(sum == 2024 || (sum && (sum%20 == 0 || sum%24 == 0)))
            return true;
        
        if(i == n || sum > 2024)
            return false;
        
        if(dp[i].find(sum) != dp[i].end())
            return dp[i][sum];
        
        int nt = solve(i+1, n, sum, coins, dp);
        if(nt)
            return dp[i][sum] = nt;
        
        return dp[i][sum] = solve(i+1, n, sum + coins[i], coins, dp);
    }
    
    int isPossible(int n , int coins[]) 
    {
        vector<unordered_map<int,bool>> dp(n);
        return solve(0,n,0,coins, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends