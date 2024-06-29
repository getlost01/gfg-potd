//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n)
    {
        vector<bool> isPrime(n+2 , true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2 ; i<n ;i++)
        {
            if(isPrime[i])
            {
                for(int j = 2 ; i*j<n ;j++)
                    isPrime[i*j]=false;
            }
        }
        for(int i = 2 ; i<n; i++)
        {
            if(isPrime[i] && isPrime[n-i])
                return {i , n-i};
        }
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends
