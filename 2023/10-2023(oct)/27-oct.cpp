//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int lcs(string &S, string &revS, int i, int j, vector<vector<int> > &dp) {
        if (i == -1 || j == -1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (S[i] == revS[j])
            return dp[i][j] = 1 + lcs(S, revS, i - 1, j - 1, dp);

        int checkS = lcs(S, revS, i - 1, j, dp);
        int checkRevS = lcs(S, revS, i, j - 1, dp);
        return dp[i][j] = max(checkS, checkRevS);
    }

    int minimumNumberOfDeletions(string S) {
        int n = S.size();
        string revS = S;
        reverse(revS.begin(), revS.end());
        vector<vector<int> > dp(n, vector<int>(n, -1));

        return n - lcs(S, revS, n - 1, n - 1, dp);
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends