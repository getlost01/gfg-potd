//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
	int maxSumIS(int arr[], int n)  
    {  
        vector<int>dp(arr, arr+n);
        
        for(int i=1;i<n;i++) 
            for(int j=0;j<i;j++) 
                if(arr[j]<arr[i]) 
                    dp[i] = max(dp[i],dp[j]+arr[i]);
                    
        int out=0;
        for(auto i: dp) 
            out = max(out,i);
        return out;
    }   
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends