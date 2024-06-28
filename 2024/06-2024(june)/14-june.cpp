//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int func (int num)
    {
        int ans=0;
        while (num)
        {
            ans+=(num%10)*(num%10)*(num%10);
            num/=10;
        }
        return ans;
    }
    string armstrongNumber(int n)
    {
        if (func(n)==n)
            return "Yes";
        else return "No";
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
