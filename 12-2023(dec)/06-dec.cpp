//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public: 
    void cntX(int n, int& X, int& cnt){
        while(n){
            if(n % 10 == X)
                ++cnt;
            n /= 10;
        }
    }

    int countX(int L, int R, int X) {
        int cnt = 0;
        
        for(int i = L + 1; i < R; i++)
            cntX(i, X, cnt);

        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}

// } Driver Code Ends