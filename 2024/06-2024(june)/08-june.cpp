//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[])
    {
        int left = 0, right = n-1;

        while(left < right) 
        {
            int mid = left + (right - left) / 2;
            if(arr1[mid] == arr2[mid])
                left = mid + 1;
            else right = mid;
        }

        if(arr1[n-1] != arr2[n-2])
            return n-1;

        return left;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends
