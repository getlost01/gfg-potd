//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int i, vector<int> adj[], vector<bool>&vis, vector<bool>& safe){
        if(safe[i])
            return true;
        if(vis[i])
            return false;
        vis[i] = 1;

        bool isSafe = true;
        for(auto edge: adj[i]){
            isSafe &= dfs(edge, adj,vis,safe);
        }
        
        return safe[i] = isSafe;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> safe(V,0),  vis(V,0);
        for(int i = 0; i< V;++i){
            if(!vis[i])
                dfs(i,adj,vis,safe);
        }
        
        vector<int> out;
        for(int i = 0; i<V;++i)
            if(safe[i])
                out.push_back(i);
            
        return out;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends