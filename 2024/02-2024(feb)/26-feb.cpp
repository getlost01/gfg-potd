//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<string> out;
    string curr;
    
    void subSeq(int i, string &s) {
        if (i == s.size()) {
            if (curr.size())
                out.push_back(curr);
            return;
        }
        
        curr.push_back(s[i]);
        subSeq(i + 1, s);
        curr.pop_back();
        subSeq(i + 1, s);
    }
    
    vector<string> AllPossibleStrings(string s) {
        subSeq(0, s);
        sort(out.begin(), out.end());
        return out;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends