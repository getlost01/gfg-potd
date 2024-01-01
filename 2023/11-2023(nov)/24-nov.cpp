//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int mod = 1e9 + 7;

    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<long long> out(n, 1), prev(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                out[j] = (prev[j] + prev[j - 1]) % mod;
            }
            prev = out;
        }
        return out;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends