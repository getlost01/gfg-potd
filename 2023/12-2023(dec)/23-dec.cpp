//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) {
        map<int,int> mp;
        int minCnt = n/k;
        for(int i = 0 ; i < n; ++i)
            ++mp[arr[i]];
        
        int out = 0;
        for(auto i: mp)
            if(i.second > minCnt)
                ++out;
                
        return out;
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

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends