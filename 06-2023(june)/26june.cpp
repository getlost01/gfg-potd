//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int MOD = 1e9+7;

    int modInverse(int num) {
        int y = 0, x = 1;
        int mod = MOD;

        while (num > 1) {
            int quo = num / mod;
            int t = mod;

            mod = num % mod;
            num = t;
            t = y;

            y = x - quo * y;
            x = t;
        }

        if (x < 0)
            x += MOD;

        return x;
    }

    int modMultiply(int a, int b) {
        a %= MOD;
        b %= MOD;
        return ((long long)a * b) % MOD;
    }

    int nCr(int n, int r) {
        if (n < r)
            return 0;
        
        // Determine the smaller value between (n-r) and r
        int a = min(n - r, r);
        int b = max(n - r, r);

        // Now we have simplify calculate (n * (n-1) * (n-2) * ... * b+1) / (a!)
        int ans = 1;
        for (int i = n; i > b; --i) 
            ans = modMultiply(ans, i);

        // Calculate modular inverse for (a!) and multiply it with the answer
        for (int i = 2; i <= a; ++i) 
            ans = modMultiply(ans, modInverse(i));

        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends