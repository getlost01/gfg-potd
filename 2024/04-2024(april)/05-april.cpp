//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int lis(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;++i)
            for(int j=0;j<i;j++)
                if(nums[i]>nums[j] && (nums[i]-nums[j])>=(i-j))
                    dp[i] = max(1+dp[j],dp[i]);
                    
        int out = 1;
        for(auto i: dp)
            out = max(out, i);
        
        return out;
    }
    int min_operations(vector<int>& nums) {
        return nums.size() - lis(nums);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends