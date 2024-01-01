//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        int distributeTicket(int n, int k) {
        int op = n/k;
        int left = (op/2)*k;
        int right = n - (op/2)*k + 1;
        
        if(right - left > (k + 1))
            return left + k + 1;
        
        return right - (right - left != 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends