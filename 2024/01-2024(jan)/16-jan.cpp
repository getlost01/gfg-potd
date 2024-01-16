//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int solve(int n, int m) {
        if (m < n)
            return 0;
        if (n == 0)
            return 1;

        int t = solve(n - 1, m / 2);
        int nt = solve(n, m - 1);

        return t + nt;
    }

    int numberSequence(int m, int n) {
        return solve(n, m);
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends