//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n)
		{
		    long long num1=1, num2=1, mod=1e9+7;
		    for(int i=1;i<n;i++)
		    {
		        long long a=(num1+num2)%mod;
		        num1=num2;
		        num2=a;
		    }
		    return num2;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
