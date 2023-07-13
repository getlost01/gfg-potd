//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isFrequencyUnique(int n, int arr[]) {
        unordered_map<int, int> freq;
        unordered_set<int> uniqueSet;

        for (int i = 0; i < n; ++i)
            ++freq[arr[i]];

        for (auto i : freq)
            uniqueSet.insert(i.second);

        return freq.size() == uniqueSet.size();
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends