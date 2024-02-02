//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int atoi(string s) {
        int n = 0; 
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s[i] == '-') 
                continue;
            if (s[i] >= '0' && s[i] <= '9')
                n = n * 10 + s[i] - '0';
            else 
                return -1; 
        }
        return (s[0] == '-') ? -n : n;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends