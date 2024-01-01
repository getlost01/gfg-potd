//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isRotated(string s1, string s2) {
        if (s1 == s2.substr(2) + s2.substr(0, 2))
            return true;
        if (s1 == s2.substr(s2.size() - 2) + s2.substr(0, s2.size() - 2))
            return true;

        return false;
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends