//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    string removeDuplicates(string str) {
        unordered_set<char> st;
        string out;
        for(auto i : str){
            if(st.find(i) == st.end()){
                out += i;
                st.insert(i);
            }
        }
        return out;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends