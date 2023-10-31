//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
        int i = 0;
        for(int j = 0; j < n; ++j){
            if(arr[j]){
                arr[i++] = arr[j];
            }
        }
        
        for(; i < n;++i){
            arr[i] = 0;
        }
	}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends