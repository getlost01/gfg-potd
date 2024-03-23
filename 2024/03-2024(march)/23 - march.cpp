//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    const int mod=1e9+7;
    vector<int> Series(int n)
    {
        vector<int>vec;
        int n1=0, n2=1;
        vec.push_back(n1);
        if (n==0)
            return vec;
        vec.push_back(n2);
        if (n==1)
            return vec;
        for (int i=2;i<=n;i++)
        {
            int num=(vec[i-1]+vec[i-2])%mod;
            vec.push_back(num);
        }
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
