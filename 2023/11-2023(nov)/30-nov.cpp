//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {   
public:
    int minimumStep(int n) {
        int cnt = 0;
        while (n > 1) {
            if (n % 3 == 0)
                n /= 3;
            else
                n -= 1;
            ++cnt;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends