//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int DivisibleByEight(string s) {
        int n = s.size();
        int l = stoi(s.substr(max(n - 3, 0)));
        return l % 8 == 0 ? 1 : -1;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends