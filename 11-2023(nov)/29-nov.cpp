//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int isEulerCircuit(int v, vector<int> adj[]) {
        int even = 0, odd = 0;
        for (int i = 0; i < v; i++) {
            if (adj[i].size() & 1)
                ++odd;
            else
                ++even;
        }

        return even == v ? 2 : (odd > 0 && odd == 2);
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends