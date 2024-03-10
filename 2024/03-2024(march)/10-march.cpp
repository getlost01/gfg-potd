//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_map<char, int> count;
	    vector<char> uniqueChars;
	    
	    for(char c: str) {
	        if(count.find(c) == count.end()) {
	           count[c] = 1;
	           uniqueChars.push_back(c);
	        }
	        else {
	            count[c]++;
	        }
	    }
	    str = "";
	    
	    for(char c: uniqueChars) str += c;
	    
	    return str;
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
