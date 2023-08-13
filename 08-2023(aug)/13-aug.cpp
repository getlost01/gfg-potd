//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int MOD = 1e9+7;
    int nthFibonacci(int n){
        if(n<3)
            return n-1;
        
        int secondLast = 0;
        int last = 1;
        int curr;
        
        n = n-1;
        while(n--){
            curr = (last +secondLast)%MOD;
            secondLast = last;
            last = curr;
        }
        
        return curr;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends