//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int isPerfectNumber(long long n) {
        if(n == 1)
            return 0;
        long long sum = 1;
        for(int i = 2; i<=sqrt(n) ; ++i){
            if(n%i == 0){
                sum += i;
                if(n/i != i)
                    sum += n/i;
            }
        }
        return sum == n;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends