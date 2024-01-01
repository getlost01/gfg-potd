//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution {
public:
    int mod = 1e9 + 7;

    long long modInv(long long a, long long b) {
        return 1 < a ? b - modInv(b % a, a) * b / a : 1;
    }

    long long numberOfPaths(int m, int n) {
        long long out = 1;

        for (int i = 0; i < m - 1; i++) {
            long long inverse = modInv(i + 1, mod);
            out = (out * (i + n)) % mod;
            out = (out * inverse) % mod;
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
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends