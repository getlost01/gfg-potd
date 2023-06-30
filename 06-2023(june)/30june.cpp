//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int isDivisible(string s) {
        int rem = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (i % 2)
                    rem += 2;
                else
                    rem++;
            }
        }
        
        return rem % 3 == 0;
    }
};



//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends