//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k, int arr[]) 
    { 
        if (k>arr[n-1])
            return arr[n-1];
        if (k<arr[0])
            return arr[0];
        int low=0, high=n-1, ans1, ans2, ans;
        while (low<=high)
        {
            int mid=low+((high-low)/2);
            if (arr[mid]==k)
                return arr[mid];
            else if (arr[mid]>k)
            {
                ans1=abs(arr[mid]-k);
                high=mid-1;
            }
            else
            {
                ans2=abs(arr[mid]-k);
                low=mid+1;
            }
        }
        if (ans1>ans2)
            ans=arr[high];
        else ans=arr[low];
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends
