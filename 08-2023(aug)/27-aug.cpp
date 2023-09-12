//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    string reverseWord(string str)
    {
        int i = 0, j = str.size()-1;
        while(i < j){
            swap(str[i], str[j]);
            ++i;
            --j;
        }
        
        return str;
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends