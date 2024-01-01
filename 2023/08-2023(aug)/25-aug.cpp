//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:	
	int isPalindrome(string S)
	{
	   int i = 0, j = S.size() - 1;
	   while(i < j){
	       if(S[i] != S[j])
	        return false;
	        ++i;
	        --j;
	   }
	   return true;
	}

};


//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends