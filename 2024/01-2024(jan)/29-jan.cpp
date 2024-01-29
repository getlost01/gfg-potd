//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int solve(int cp, int cs, int sz, string s, vector<vector<int>>& dp) {
        if (cp == sz) 
            return 1;
            
        if (dp[cp][cs] != -1) 
            return dp[cp][cs];
            
        int sm = 0, cnt = 0;

        for (int i = cp; i < sz; i++) {
            sm += s[i] - '0';
            if (sm >= cs) 
                cnt += solve(i + 1, sm, sz, s, dp);
        }

        return dp[cp][cs] = cnt;
    }

    int TotalCount(string str) {
        int sm = 0;
        for (auto i : str) 
            sm += i - '0';
			
        vector<vector<int>> dp(str.size() + 1, vector<int>(sm + 1, -1));

        return solve(0, 0, str.size(), str, dp);
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends