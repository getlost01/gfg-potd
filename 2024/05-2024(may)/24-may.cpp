//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int count_no_of_subset(vector<int> &arr, int sum1, vector<vector<long long int>> &t)
    {
        for(int i=0;i<arr.size()+1;i++)
        {
            for(int j=0;j<sum1+1;j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        
        long long int mod=1e9+7;
        
        for(int i=1;i<arr.size()+1;i++
        {
            for(int j=0;j<sum1+1;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j]=((t[i-1][j])+(t[i-1][j-arr[i-1]]))%mod;
                else t[i][j]=(t[i-1][j]);
            }
        }
        
        return t[arr.size()][sum1];
    }
    
    int countPartitions(int n, int d, vector<int>& arr)
    {
        long long int sum=0;
        for(int i: arr)
            sum+=i;
        if((sum+d)%2!=0 || sum<d)
            return 0;
        long long int sum1=(sum+d)/2;
        sum1=min(sum1, sum - sum1);
        vector<vector<long long int>> t(n+1,vector<long long int>(sum1+1));
        return count_no_of_subset(arr,sum1,t);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
