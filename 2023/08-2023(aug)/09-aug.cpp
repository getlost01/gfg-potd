//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public: 
    long long int largestPrimeFactor(int n){
        int out = 2;
        int checkUpto = sqrt(n);
        for(int i = 2; i <= checkUpto;++i){
            while(n%i == 0){
             n = n/i;
             out = max(out,i);
            }
        }
        out = max(out, n);
        return out;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends