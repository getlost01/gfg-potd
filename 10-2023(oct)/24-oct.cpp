//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    bool isPalin(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    int check(int i, int j, string& s, vector<vector<int>>& dp){
        if(i >= j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(isPalin(i,j,s)) return dp[i][j] = 0;

        int out = INT_MAX;
        for(int k = i;k<j;++k){
            if(isPalin(i,k,s)){
                out = min(out,1 + check(k+1,j,s,dp));
            }
        }
        return dp[i][j] = out;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        check(0,n-1,str,dp);
        return check(0,n-1,str,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends