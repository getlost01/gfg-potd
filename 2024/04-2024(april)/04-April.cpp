//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long sumSubstrings(string s){
        long long sum = 0;
        int mod = 1e9+7;
        int n = s.size();
        long mul = 1; 
        for (int i = n - 1; i >= 0; --i) {
            sum += ((s[i] - '0') * mul * (i + 1)) % mod;
            sum %= mod;
            mul = (mul * 10 + 1) % mod; 
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends