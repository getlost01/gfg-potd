//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n)
    {
        int len=s.length();
        for (int i=0;i<r;i++)
        {
            string temp=s;
            for (int j=0;j<len;j++)
            {
                if (temp[j/2]=='0')
                    s[j]='0'+(j%2);
                else s[j]='1'-(j%2);
            }
        }
        return s[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
