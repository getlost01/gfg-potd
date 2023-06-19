//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    void arrange(long long arr[], int n) {
        long long offset =1e5; 
        for (int i = 0; i < n; i++) {
            arr[i] = (arr[arr[i]] % offset) * offset + arr[i]; 
        }
        // set the array with new value as "newValue = newvalue*offset + oldValue"

        for (int i = 0; i < n; i++) {
            arr[i] = arr[i]/offset;
        }
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends