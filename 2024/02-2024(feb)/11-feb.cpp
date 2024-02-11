//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> recamanSequence(int n){
        vector<int> a(n+1,0);
        unordered_set<int> st;
        for(int i = 1; i <= n; ++i){
            if((a[i-1] - i) > 0 && st.find(a[i-1] - i) == st.end())
                a[i] = a[i-1] - i;
            else
                a[i] = a[i-1] + i;
            st.insert(a[i]);
        }
        return a;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends