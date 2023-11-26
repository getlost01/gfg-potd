//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> pattern(int N) {
        if (N <= 0)
            return {N};
            
        int toggle = -5;
        int c = N;
        vector<int> out;
        
        do {
            out.push_back(c);
            c += toggle;
            if (c <= 0)
                toggle = -toggle;
        } while (c != N);
        
        out.push_back(N);
        return out;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends