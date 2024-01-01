//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void dfs(int k, string prev, unordered_set<string> &seen, string &edges) {
        for (char i = '0'; i <= ('0' + k - 1); i++) {
            string cur = prev + i;
            if (seen.find(cur) == seen.end()) {
                seen.insert(cur);
                dfs(k, cur.substr(1), seen, edges);
                edges += i;
            }
        }
    }

    string findString(int n, int k) {
        unordered_set<string> seen;
        string startingNode = string(n - 1, '0');
        string edges;
        dfs(k, startingNode, seen, edges);

        string ret = edges + startingNode;
        return ret;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends