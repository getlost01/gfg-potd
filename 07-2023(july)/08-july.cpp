//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool find(int arr[], int l, int r, int target) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] == target)
                return true;
            
            if (arr[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
  
    bool findTriplets(int arr[], int n) { 
        sort(arr, arr + n);
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                
                int target = arr[i] + arr[j];
                target = -1 * target;
                
                if (target >= arr[j + 1]) {
                    if (find(arr, j + 1, n - 1, target))
                        return true;
                }
                
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends