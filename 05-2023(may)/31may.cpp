//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int,greater<>> mp;
        for(int i = 0;i<n;++i){
            ++mp[arr[i]];
        }
        int nax = INT_MAX;
        int out = -1;
        for(auto i:mp){
            if(nax>i.second){
                nax = i.second;
                out = i.first;
            }
        }
        return out;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends