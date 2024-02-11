//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long numberOfPath(int n, int k, vector<vector<int>> arr)
    {
        int dr[]={1, 0};
        int dc[]={0, 1};
        auto valid=[&](int x, int y)->bool
        {
            if(x<0 || x>=n || y<0 || y>=n)
                return 0;
            return 1;
        };
        vector<vector<vector<long long>>>dp(n, vector<vector<long long>>(n, vector<long long>(k+1, -1)));
        function<long long(int, int, int)>helper=[&](int r, int c, int sum)->long long
        {
            if(r==n-1 and c==n-1)
                return dp[r][c][sum]=sum==arr[r][c];
            if(dp[r][c][sum]!=-1)
                return dp[r][c][sum];
            dp[r][c][sum]=0;
            if(arr[r][c]<=sum)
            {
                for(int dir=0;dir<2;dir++)
                {
                    int nr=r+dr[dir];
                    int nc=c+dc[dir];
                    if(valid(nr, nc))
                        dp[r][c][sum]+=helper(nr, nc, sum-arr[r][c]);
                }            
            }
            return dp[r][c][sum];
        };
        return helper(0, 0, k);
    }
    
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends
