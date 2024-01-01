//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> out;
        int i = 0;
        long long sum = 0;
        for(int j = 0; j< n;++j){
            sum += arr[j];
            while(sum > s && i<j){
                sum -= arr[i];
                ++i;
            }
            if(sum == s){
                out.push_back(i+1);
                out.push_back(j+1);
                return out;
            }
        }
        
        out.push_back(-1);
        return out;
    }
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends