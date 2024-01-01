//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto i : nums)
            ++mp[i];
        
        priority_queue<pair<int, int>> pq;
        
        for (auto itr : mp) {
            pq.push({itr.second, itr.first});
        }
        
        vector<int> out;
        while (!pq.empty() && k--) {
            out.push_back(pq.top().second);
            pq.pop();
        }
        
        return out;
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
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends