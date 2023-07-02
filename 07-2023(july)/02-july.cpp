//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int setSetBit(int x, int y, int l, int r) {
        int maskLen = r - l + 1;
        int mask = (1 << maskLen) - 1;
        mask = mask << (l - 1);
        y = y & mask;
        return (x | y);  
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends