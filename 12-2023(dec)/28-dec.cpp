//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool solve(int i, int j, string &w, string &p, vector<vector<int>>& dp){
        if(i == w.size())
            return j == p.size();
            
        if(j == p.size())
            return w[i] == '*' && solve(i + 1, j, w, p, dp);
        
        if(dp[i][j]!=-1)
          return dp[i][j];
      
        bool ans = false;
        
        if(w[i]==p[j] || w[i]=='?')
            ans = solve(i+1,j+1, w, p,dp);
        else if(w[i]=='*')
            ans = solve(i,j+1, w, p,dp) || solve(i+1,j, w, p,dp);
        
        return dp[i][j] = ans;
    }
    
    bool match(string w, string p){
        vector<vector<int>> dp(w.size(), vector<int> (p.size(), -1));
        return solve(0,0,w,p,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends