//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int a[], int n, int k) {
        priority_queue<int> pq;
        for(int i = 0 ; i<n ;++i)
            pq.push(a[i]);
            
        long long out = 0, pqTop;
        while(k--){
            pqTop = pq.top();
            pq.pop();
            out += pqTop;
            pq.push(pqTop/2);
        }
        return out;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends