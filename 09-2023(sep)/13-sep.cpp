//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if((!S & N > 1) || N*9 < S)
            return "-1";
        string out;
        for(int i = 0; i<N;++i){
            if(S>=9){
                out += '9';
                S-=9;
            }else{
                if(S){
                     out += to_string(S);
                     S = 0;
                }
                else
                    out += '0';
            }
        }
        return out;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends