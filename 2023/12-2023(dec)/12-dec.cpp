//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> dp;

    bool isValid(int& i, int& j, int& n, int& m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int traverse(int i, int j, vector<vector<int>>& M, int& n, int& m) {
        int out = 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        for (int d = -1; d <= 1; ++d) {
            int x = i + d;
            int y = j + 1;
            if (isValid(x, y, n, m))
                out = max(out, traverse(x, y, M, n, m));
        }
        return dp[i][j] = out + M[i][j];
    }

    int maxGold(int n, int m, vector<vector<int>> M) {
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int out = 0;
        for (int i = 0; i < n; ++i) {
            out = max(out, traverse(i, 0, M, n, m));
        }
        return out;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends