//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string binaryNextNumber(string s) {
        int n = s.size();
        int i = n - 1;
        while(i >= 0 && s[i] == '1')
            s[i--] = '0';
        
        if(i == -1)
            s = "1" + s;
        else
            s[i] = '1';
        
        i = 0;
        while(s[i] == '0')
            ++i;
        
        return s.substr(i);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends