//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        string revStr=str;
        reverse(revStr.begin(), revStr.end());
        return (isKPalDP(str, revStr, n, n)<=k*2);
    }

private:
    int isKPalDP(string str1, string str2, int m, int n)
    {
        int dp[m+1][n+1];
        for (int i=0;i<=m;i++)
        {
            for (int j=0;j<=n;j++)
            {
                if (i==0)
                    dp[i][j]=j;
                else if (j==0)
                    dp[i][j]=i;
                else if (str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
