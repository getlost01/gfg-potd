//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool checkTriplet(int arr[], int n) {
        unordered_set<int> s;

        for (int i = 0; i < n; ++i)
            s.insert(arr[i] * arr[i]);

        for (auto a : s) {
            for (auto b : s) {
                if (s.find(a + b) != s.end())
                    return true;
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends