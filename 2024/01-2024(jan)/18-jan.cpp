//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int> range(n, -1);

        for(int i = 0; i < n ; ++i){
            int l = max(0, i - gallery[i]);
            int r = min(n - 1, i + gallery[i]);
            for(int j = l; j <= r; ++j){
                range[j] = max(range[j], r);
            }
        }
        
        int count = 0, last = -1;

        for (int i = 0; i < n; ++i) {
            if (range[i] == -1) {
                return -1;
            }

            if (i > last) {
                ++count;
                last = range[i];
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends