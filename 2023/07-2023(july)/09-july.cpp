//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int missingNumber(int arr[], int n) 
    { 
       unordered_map<int,bool> mp;
       for(int i = 0; i<n;++i){
           mp[arr[i]] = 1;
       }
       int nin = 1;
       while(true){
           if(mp.find(nin) == mp.end())
             return nin;
            ++nin;
       }
    } 
};


//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends