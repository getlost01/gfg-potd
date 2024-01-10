//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int out = 0, sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int rem = sum % k;
            
            if (rem < 0)
                rem += k;
            
            if (mp.find(rem) != mp.end())
                out = max(out, i - mp[rem]);
            else
                mp[rem] = i;
        }
        
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends