//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int is_bleak(int n) {
        for(int i = 1; i <= log2(n); ++i) {
            int x = n - i;
            int setBits = __builtin_popcount(x);
            if(setBits + x == n)
                return 0;
        }
        return 1;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends