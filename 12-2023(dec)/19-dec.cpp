//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution {
public:
    int posOfRightMostDiffBit(int m, int n) {
        if (m == n)
            return -1;
            
        int res = m ^ n;
        res = res & (-res);
        return log2(res) + 1;
    }
};


//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends