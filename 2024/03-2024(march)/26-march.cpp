//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool solve(int ii, string &s, int n) {
        if (ii >= n)
            return true;

        int a = 0, b = 0;
        for (int i = ii; i < n; ++i) {
            a = a * 10 + (s[i] - '0');
            b = 0;
            for (int j = i + 1; j < n; ++j) {
                b = b * 10 + (s[j] - '0');
                string c = to_string(a + b);
                if (c.size() <= n - j - 1)
                    if (c == s.substr(j + 1, c.size()))
                        if (solve(j + c.size() + 1, s, n))
                            return true;
            }
        }
        return false;
    }

    bool isAdditiveSequence(string n) {
        return solve(0, n, n.size());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends