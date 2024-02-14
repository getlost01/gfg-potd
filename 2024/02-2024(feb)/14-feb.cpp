//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int timer = 0;
    vector<vector<int>> ans;
    vector<int> vis, dis, low;

    void dfs(int node, int parent, vector<int> adj[]) {
        ++timer;
        vis[node] = 1;
        dis[node] = low[node] = timer;
        for (auto it : adj[node]) {
            if (it == parent)
                continue;
            else if (!vis[it])
                dfs(it, node, adj);

            low[node] = min(low[node], low[it]);
            if (low[it] > dis[node])
                ans.push_back({min(it, node), max(it, node)});
        }
    }

    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        vis = vector<int>(v, 0);
        dis = low = vector<int>(v, -1);
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0)
                dfs(i, -1, adj);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends