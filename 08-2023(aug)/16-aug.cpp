//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int MOD = 1e9 + 7;
    int findCatalan(int n) 
    {
        long long c[n + 1] = {0};
        c[0] = c[1] = 1;
		
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                c[i] = (c[i] + (c[j] * c[i - 1 - j])) % MOD;
            }
        }

        return (int)c[n];
    }
};


//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends