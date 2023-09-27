//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> out;
        int nin = INT_MAX;
        
        int a = 0, b = m - 1;
        while(a < n && b >= 0){
            int sum = arr[a] + brr[b];
            if(abs(sum - x) < nin){
                out = {arr[a], brr[b]};
                nin = abs(sum - x);
            }
            if(sum > x)
                --b;
            else
                ++a;
        }
        return out;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends