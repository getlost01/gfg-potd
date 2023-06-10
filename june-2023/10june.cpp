//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            vector<int> neq,pos;
            for(int i = 0;i<n;++i){
                if(arr[i]<0){
                    neq.push_back(arr[i]);
                }else{
                    pos.push_back(arr[i]);
                }
            }
            int sz = neq.size();
            for(int i = 0;i<sz;++i)
                arr[i] = neq[i];
            for(int i = sz; i<n ;++i)
                arr[i] = pos[i - sz];
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends