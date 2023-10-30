//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long int sumXOR(int arr[], int n) {
        long long int out = 0;
        for (int i = 0; i < 32; ++i) {
            long long int ones = 0;
            int mask = 1 << i;
            for (int j = 0; j < n; ++j) {
                if ((arr[j] & mask) != 0) {
                    ones++;
                }
            }
            out += (ones * (n - ones) * mask);
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
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends