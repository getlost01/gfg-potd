//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int numberSequence(int m, int n)
    {
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        for (int i=1;i<=m;i++)
            dp[i][1]=1;
        for (int j=2;j<=n;j++)
        {
            for (int i=1;i<=m;i++)
            {
                for (int k=i*2;k<=m;k++)
                {
                    dp[k][j]=(dp[k][j]+dp[i][j-1])%1000000007;
                }
            }
        }
        int result=0;
        for (int i=1;i<=m;i++)
            result = (result+dp[i][n])%1000000007;
        return result;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
