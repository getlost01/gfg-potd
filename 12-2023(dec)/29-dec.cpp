//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int kSubstrConcat(int n, string s, int k) {
        if (n % k > 0)
            return 0;

        unordered_set<string> st;
        for (int i = 0; i < n / k; ++i)
            st.insert(s.substr(i * k, k));

        return st.size() <= 2;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends