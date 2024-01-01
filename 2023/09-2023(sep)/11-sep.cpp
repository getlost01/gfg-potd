//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    bool isLucky(int n) {
        int cnt = 2;
        while(cnt <= n){
            if(n % cnt == 0)
                return false;
            
            n -= n/cnt;
            ++cnt;
        }
        
        return true;
    }
};


//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends