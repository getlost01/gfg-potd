//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution {
public:
    bool subArrayExists(int arr[], int n) {
        int sum = 0;
        unordered_set<int> s;
        s.insert(0);
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (s.find(sum) != s.end())
                return true;
            s.insert(sum);
        }
        
        return false;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends