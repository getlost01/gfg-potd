//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        unordered_map<int,int> mp;
        int s = 0;
        for(int i = N1-1;i>=0;--i){
            s += S1[i];
            ++mp[s];
        }
        s = 0;
        for(int i = N2-1;i>=0;--i){
            s += S2[i];
            if(mp.find(s)!=mp.end())
            ++mp[s];
        }
        s = 0;
        for(int i = N3-1;i>=0;--i){
            s += S3[i];
            if(mp.find(s)!=mp.end())
            ++mp[s];
        }
        int out = 0;
        for(auto i: mp){
            if(i.second == 3){
                out = max(out,i.first);
            }
        }
        return out;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends