//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution {
public:
    int FindMaxSum(int arr[], int n) {
        vector<int> dp(n, 0);
        int out = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i >= 2)
                dp[i] = dp[i - 2];
            if (i >= 3)
                dp[i] = max(dp[i], dp[i - 3]);

            dp[i] += arr[i];
            out = max(out, dp[i]);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends