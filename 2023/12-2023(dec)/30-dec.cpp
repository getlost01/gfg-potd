//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> mp;
        for(int i = 0; i < n ; ++i)
            ++mp[arr[i]];
        
        string out;
        int cnt = 0;
        for(auto i: mp){
            if(cnt < i.second){
                cnt = i.second;
                out = i.first;
            } else if(cnt == i.second){
                if(out > i.first)
                    out = i.first;
            }
        }
        return {out, to_string(cnt)};
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends