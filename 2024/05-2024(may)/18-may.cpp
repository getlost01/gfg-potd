//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int size=a.size();
        int low=0, high=size-1;
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (a[mid]>a[mid-1] && a[mid]>a[mid+1])
                return a[mid];
            else if (a[mid]>a[mid-1] && a[mid]<a[mid+1])
                low=mid+1;
            else high=mid-1;
        }
        return a[size-1];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends
