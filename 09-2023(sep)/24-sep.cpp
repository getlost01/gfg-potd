//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        int cnt[n] = {0};
        for(int i = 0; i<n;++i)
           ++cnt[arr[i]];
         
        vector<int> out;
        for(int i = 0; i<n;++i)
            if(cnt[i] > 1)
                out.push_back(i);
        
        if(out.size())
            return out;
        
        return {-1};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends