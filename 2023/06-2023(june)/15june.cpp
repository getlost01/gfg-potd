//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool ispalin(string& s, int i ,int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;

            ++i; --j;
        }
        return true;
    }
    string longestPalin (string s) {
        int n = s.size();
        string out;
        out.push_back(s[0]);
        int ms = 1;
        for(int i = 0; i<n-1 ;++i){
            for(int j = n-1; j>i; --j){
                if((j-i+1)>ms && ispalin(s,i,j)){
                    ms = j-i+1;
                    out = s.substr(i,j-i+1);
                }
            }
        }
        return out;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends