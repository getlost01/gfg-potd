//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<bool> visited(V, false);
        vector<int> level(V, 0);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    level[neighbor] = level[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        if (visited[X])
            return level[X];
        else
            return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends
