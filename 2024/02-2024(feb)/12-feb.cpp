//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long sequence(int n){
        long long mod = 1e9 + 7;
        long long out = 0, c = 1;
        for(int i = 1; i <= n; ++i){
            long long temp = 1;
            for(int j = 0; j < i ; ++j){
                temp *= c++;
                temp %= mod;
            }
            out = (out + temp) % mod;
        }
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
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends