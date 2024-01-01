//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        long out = 0, range = 0;
        long i = 0;
        
        for (long j = 0; j < n; ++j)
        {
            if (a[j] >= L && a[j] <= R)
                range = j - i + 1;
            else if (a[j] > R)
                range = 0, i = j + 1;

            out += range;
        }
        
        return out;
    }
};



//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends