//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int solve(int i, int total, vector<int>& cost, vector<vector<int>>& dp){
        if(i == cost.size())
            return 0;

        if(dp[i][total] != -1)
            return dp[i][total];

        int t = 0, nt = 0;
        if(total >= cost[i]){   // for taking case
            int ac = cost[i] - floor(0.9 * cost[i]);    // actual cost that the user bears
            t = 1 + solve(i + 1, total - ac, cost, dp);
        }
        nt = solve(i + 1, total, cost, dp);	// for non taking case

        return dp[i][total] = max(t, nt);
    }

    int max_courses(int n, int total, vector<int>& cost) {
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        return solve(0, total, cost, dp);
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends