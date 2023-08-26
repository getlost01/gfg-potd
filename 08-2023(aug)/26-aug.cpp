//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int longestKSubstr(string s, int k) {
        
        unordered_map<char, int> cnt;
        int i = 0, n = s.size();
        int c = 0, out = -1;
        
        for (int j = 0; j < n; ++j) {
            if (cnt[s[j]] == 0)
                ++c;

            ++cnt[s[j]];
            
            while (c > k && i < j) {
                --cnt[s[i]];
                if (cnt[s[i]] == 0)
                    --c;
                ++i;
            }
            
            if (c == k) 
                out = max(out, j - i + 1);
        }

        return out;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends