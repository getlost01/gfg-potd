//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i)
            v.push_back({price[i], i + 1});

        sort(v.begin(), v.end());

        int out = 0;

        for (auto i : v) {
            int maxBuy = min(k / i.first, i.second);
            out += maxBuy;
            k -= i.first * maxBuy;
        }
        return out;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends