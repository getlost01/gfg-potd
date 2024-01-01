//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
public:	
    int lower_bound(int arr[],int n, int x){
        int l = 0, r = n - 1;
        while(l < r){
            int m = (l + r) / 2;
            
            if(x <= arr[m])
                r = m;
            else
                l = m + 1;
        }
            
        return l;
    }

    int upper_bound(int arr[],int n, int x){
        int l = 0, r = n - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(x >= arr[m])
                l = m+1;
            else
                r = m;
        }
        
        if(l < n && arr[l] <= x)
            l++;
            
        return l;
    }
    
    
	int count(int arr[], int n, int x) {
	    int start = lower_bound(arr,n,x);
	    if(arr[start] != x)
	        return 0;
	       
	    int last = upper_bound(arr,n,x);
	    
	    return last - start;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends