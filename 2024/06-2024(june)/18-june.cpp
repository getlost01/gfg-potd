//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r)
    {
        int limit = 4*r*r;
        int numRects = 0;
        int tempRects = -1;
        int diff = -1;
        for(int l = 1; ; ++l)
        {
            diff = limit - l*l;
            if(diff <= 0) 
                break;
            tempRects = (int)pow(diff, 0.5);
            if(tempRects == 0)
                break;
            numRects += tempRects;
        }
        return numRects;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends
