//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findWinner(int n, int A[]) {
        int XOR = 0;
        for(int i = 0; i < n; i++)
            XOR ^= A[i];

        if(XOR == 0)
            return 1;

        return n % 2 == 0 ? 1 : 2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends