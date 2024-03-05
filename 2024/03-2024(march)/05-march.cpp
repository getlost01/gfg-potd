//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        if (n==1)
            return 0;
        int ans=-1;
        int lmin[n];
        int rmax[n];
        lmin[0]=a[0];
        for (int i=1;i<n;i++)
        {
            lmin[i]=min(lmin[i-1], a[i]);
        }
        rmax[n-1]=a[n-1];
        for (int j=n-2;j>=0;j--)
        {
            rmax[j]=max(rmax[j+1], a[j]);
        }
        int i=0, j=0;
        while (i<n && j<n)
        {
            if (lmin[i]<=rmax[j])
            {
                ans=max(ans, j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
