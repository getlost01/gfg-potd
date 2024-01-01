//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size() % 2 != 0)
            return false;
            
        vector<int> cnt(k, 0);
        
        for(auto i: nums)
            ++cnt[i % k];
        
        int l = 1, r = k - 1;
        
        while(l < r){
            if(cnt[l] != cnt[r])
                return false;
            ++l;
            --r;
        }
        
        if((l == r && cnt[l] % 2 != 0) || cnt[0] % 2 != 0)
            return false;
        
        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends