//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int n, string s)
    {
        int dp[n][n][2];
        const int mod=1003;
        for(int i=n-1;i>-1;i-=2)
        {
            for(int j=i;j<n;j+=2)
            {
                if(i==j)
                {
                    dp[i][j][1]=s[i]=='T';
                    dp[i][j][0]=s[i]=='F';
                }
                else
                {
                    dp[i][j][1]=dp[i][j][0]=0;
                    for(int k=i;k<j;k+=2)
                    {
                        int f1=dp[i][k][1], f0=dp[i][k][0], s1=dp[k+2][j][1], s0=dp[k+2][j][0];
                        if(s[k+1]=='&')
                        {
                            dp[i][j][1]=(dp[i][j][1]+(f1*s1)%mod)%mod;
                            dp[i][j][0]=(dp[i][j][0]+(f1*s0)%mod+(f0*s1)%mod+(f0*s0)%mod)%mod; 
                        }
                        else if(s[k+1]=='|')
                        {
                            dp[i][j][1]=(dp[i][j][1]+(f1*s0)%mod+(f0*s1)%mod+(f1*s1)%mod)%mod; 
                            dp[i][j][0]=(dp[i][j][0]+(f0*s0)%mod)%mod;
                        }
                        else
                        {
                            dp[i][j][1]=(dp[i][j][1]+(f1*s0)%mod+(f0*s1)%mod)%mod;
                            dp[i][j][0]=(dp[i][j][0]+(f1*s1)%mod+(f0*s0)%mod)%mod;
                        }
                    }
                }
            }
        }
        return dp[0][n-1][1];
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
