//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {   
            int mask_16 = (1<<16) - 1;
            d = d%16;
            
            vector<int> out(2);
            out[0] = (n<<d|(n>>(16-d)));
            out[0] = out[0] & mask_16;  
            
            out[1] = (n>>d|(n<<(16-d)));
            out[1] = out[1] & mask_16;
            
            return out;
        }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends