//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void update(int arr[], int n, int updates[], int k)
    {
        vector<int> out(n+1,0);
        for(int i = 0;i<k;++i){
            ++out[updates[i]];
        }
        arr[0] = out[1];
        for(int i = 2;i<=n;++i){
            arr[i-1] = arr[i-2] + out[i];
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends