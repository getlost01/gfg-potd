//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long mod = 1e9+7;
    long long powerexpo(long long a, long long n) {
        long long res = 1LL;
        while (n) {
            if (n & 1) {
                res = (res % mod * a % mod) % mod;
                --n;
            } else {
                a = (a % mod * a % mod) % mod;
                n >>= 1;
            }
        }
        return res;
    }

    long long power(int N, int R) {
        return powerexpo(N, R);
    }
};


//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends