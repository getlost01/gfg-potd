//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void dfs(int i, vector<int>& out,vector<int> adj[], vector<bool>& vis){
        out.push_back(i);
        
        for(auto node: adj[i]){
            if(!vis[node]){
                vis[node] = true;
                dfs(node, out, adj, vis);
            }
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> out;
        vector<bool> vis(v,0);
        
        vis[0] = true;
        dfs(0,out,adj,vis);
        
        return out;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends