//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> result;
        vector<int> state(V, 0);

        for (int i=0; i<V;i++)
        {
            if (isSafe(i, adj, state, result))
            {
                result.push_back(i);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }

    bool isSafe(int node, vector<int> adj[], vector<int>& state, vector<int>& result)
    {
        if (state[node] == 1)
        {
            return false;
        }
        if (state[node] == 2)
        {
            return true;
        }

        state[node] = 1;
        for (int neighbor : adj[node])
        {
            if (!isSafe(neighbor, adj, state, result))
            {
                return false;
            }
        }
        state[node] = 2;
        return true;
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
