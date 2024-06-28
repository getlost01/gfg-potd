//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n)
    {
        long long sum = 0, org = 0;
        for(int i=0; i<n; i++)
        {
            sum += a[i];
            org += i * 1LL * a[i];
        }
        long long ans = org;
        for(int i=n-1; i>=0; i--)
        {
            org += sum - (1LL * a[i] * n);
            ans = max(ans, org);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends
