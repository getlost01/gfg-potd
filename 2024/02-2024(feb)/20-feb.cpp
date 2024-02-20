//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool can(int i, string& A, vector<string> & B){
        if(i == A.size())
            return true;
            
        for(auto str: B){
            if(str.size() <= (A.size() - i) && A.substr(i, str.size()) == str){
                if(can(i + str.size(), A, B))
                    return true;
            }
        }
        
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
       return can(0,A,B);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends