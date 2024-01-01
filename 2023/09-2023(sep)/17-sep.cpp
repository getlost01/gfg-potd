//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    vector<long long> printFibb(int n) 
    {
        if(n<=2)
            return vector<long long>(n,1);
            
        vector<long long> out(n);
        out[0] = out[1] = 1;
        for(int i = 2;i <n;++i){
            out[i] = out[i-1] + out[i-2];
        }
        return out;
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
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends