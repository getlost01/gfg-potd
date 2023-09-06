//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int i, vector<int>adj[], vector<int>& vis, vector<int>& topo){
        vis[i] = 1;
        for(auto edge: adj[i]){
            if(!vis[edge]){
                dfs(edge, adj,vis,topo);
            }
        }
        topo.push_back(i);
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int cnt = 0;
	    vector<int> vis(V,0), topo;
	    for (int i = 0; i < V; ++i) {
            if (!vis[i])
                dfs(i,adj,vis,topo);
        }
	    
	    if(topo.size() == V){
            int motherVer = topo.back();
	        vis.assign(V, 0);
            topo.clear();
	        dfs(motherVer, adj, vis, topo);
	        // for(auto i: topo)
	        //     cout<<i<<" ";
	        if(topo.size() == V)
	            return motherVer;
	    }
	    
	    return -1;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
