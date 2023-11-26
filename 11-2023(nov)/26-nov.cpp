//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void solve(int n, vector<int>& out) {
        out.push_back(n);
        if (n <= 0)
            return;
        solve(n - 5, out);
        out.push_back(n);
    }

    vector<int> pattern(int N) {
        vector<int> out;
        solve(N, out);
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