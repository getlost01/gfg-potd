## 18. Eventual Safe States
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/eventual-safe-states/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

A node is terminal if all child nodes are terminal or having no childs. To find the eventual safe states in a directed graph, I use a depth-first search (DFS) approach. With DFS, I check all connected nodes of a current node, and if all nodes are eventually terminals, I mark this node as terminal as well.

We can implement this approach as follows:

- I start by iterating through each node and perform a DFS to determine if it's safe.
- If I visit a node that has already been determined as safe, I return true.
- If I encounter a node that is already in the process of being visited (marked as visited but not yet determined safe), I return false to avoid cycles.
- For each edge, I recursively call the DFS function. If all edges of a node lead to safe states, I mark that node as safe.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V + E)`, where `V` is the number of nodes (vertices) and `E` is the number of edges in the graph.
- **Auxiliary Space Complexity**: `O(V)`, where `V` is the number of nodes. This space is used for marking nodes as safe or not.

### Code (C++)
```cpp
class Solution {
  public:
    bool dfs(int i, vector<int> adj[], vector<bool>& vis, vector<bool>& safe) {
        if (safe[i])
            return true;
        if (vis[i])
            return false;
        vis[i] = true;

        bool isSafe = true;
        for (auto edge : adj[i]) {
            isSafe &= dfs(edge, adj, vis, safe);
        }

        return safe[i] = isSafe;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> safe(V, false), vis(V, false);
        for (int i = 0; i < V; ++i) {
            if (!vis[i])
                dfs(i, adj, vis, safe);
        }

        vector<int> out;
        for (int i = 0; i < V; ++i)
            if (safe[i])
                out.push_back(i);

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.