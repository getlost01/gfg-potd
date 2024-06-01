//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        vector<int> c(26, 0);
        for(int i = 0; i < s.size(); ++i)
            ++c[s[i] - 'a'];
            
        int cnt = 0;
        for(int i = 0; i < 26; ++i)
            if(c[i] && c[i]%2 == (i+1)%2)
                ++cnt;
                
        return cnt%2?"ODD":"EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends