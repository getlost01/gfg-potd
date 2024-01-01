//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        queue<pair<int, int>> q;
        vector<int> vis(n, INT_MAX);

        vector<vector<pair<int, int>>> graph(n);
        for (auto node : edges) {
            int s = node[0];
            int e = node[1];
            int w = node[2];
            graph[s].push_back({ e, w });
        }

        q.push({ 0, 0 });
        vis[0] = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int weight = q.front().second;
            q.pop();

            for (auto& i : graph[node]) {
                int next = i.first;
                int w = i.second;
                
                if (weight + w < vis[next])
                    q.push({ next, weight + w });
                vis[next] = min(vis[next], weight + w);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (vis[i] == INT_MAX)
                vis[i] = -1;
        }

        return vis;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends