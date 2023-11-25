//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void shuffleArray(int arr[], int n) {
        int offset = 1e5;
        for (int i = 0; i < n / 2; ++i) {
            arr[i * 2] += (arr[i] % offset) * offset;
            arr[i * 2 + 1] += (arr[n / 2 + i] % offset) * offset;
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = arr[i] / offset;
        }
    }
};


//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends