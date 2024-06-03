//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        int mod = 1e9+7;
        long out = 1;
        int x = 0, y = 1;
        for(int i = 3; i <= n ;++i){
            out = (out*2 + x + y)%mod;
            int z = x;
            x = y;
            y = (x + z)%mod;
        }
        return out;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends