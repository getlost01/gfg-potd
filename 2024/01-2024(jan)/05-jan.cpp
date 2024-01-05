//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int mod = 1e9 + 7;

    int TotalWays(int N) {
        long long curr, prev, next;
        curr = prev = 1;
        for (int i = 1; i <= N; ++i) {
            next = (curr + prev) % mod;
            prev = curr;
            curr = next;
        }

        return (curr * curr) % mod;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends