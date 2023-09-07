//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int MOD = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end)
            return 0;
        
        int n = arr.size();
        vector<int> dp(MOD, -1);
        
        dp[start] = 0;
    
        queue<int> q;
        q.push(start);
    
        while (!q.empty()) {
            int current = q.front();
            q.pop();
    
            for (int i = 0; i < n; i++) {
                long long next = 1LL * current * arr[i] % MOD;
    
                if (dp[next] == -1) {
                    dp[next] = dp[current] + 1;
                    q.push(next);
    
                    if (next == end) {
                        return dp[next];
                    }
                }
            }
        }
    
        return -1;  
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends