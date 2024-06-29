//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool func (string str)
    {
        string rev=str;
        reverse(rev.begin(), rev.end());
        return str==rev;
    }
    string pattern(vector<vector<int>> &arr)
    {
        int size=arr.size();
        for (int i=0;i<size;i++)
        {
            string str="";
            for (int j=0;j<size;j++)
                str+=to_string(arr[i][j]);
            if (func(str))
            {
                string ans="";
                ans+=to_string(i);
                ans+=" R";
                return ans;
            }
        }
        for (int i=0;i<size;i++)
        {
            string str="";
            for (int j=0;j<size;j++)
                str+=to_string(arr[j][i]);
            if (func(str))
            {
                string ans="";
                ans+=to_string(i);
                ans+=" C";
                return ans;
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
