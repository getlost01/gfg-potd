## 14. Find all Critical Connections in the Graph
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/critical-connections/1)

### My Approach
To find all critical connections in the graph, I used Tarjan's algorithm, which is based on depth-first search (DFS). Here's a brief explanation of the approach:
1. Initialize variables `timer`, `vis`, `dis`, `low`, and `ans`.
2. Implement a depth-first search (DFS) function to traverse the graph.
3. During DFS traversal, mark the visited nodes and update the discovery time (`dis`) and lowest reachable node (`low`) for each node.
4. If a backward edge is found (i.e., `low[it] > dis[node]`), it indicates a critical connection. Store the edge in the `ans` vector.
5. Sort the `ans` vector to maintain order.
6. Return the `ans` vector containing all critical connections.

#### Note:
**I personally recommend [this video](https://www.youtube.com/watch?v=qrAub5z8FeA "this video") for detailed learning about Tarjan's algorithm.**

### Time and Auxiliary Space Complexity

- **Time Complexity** : The time complexity of Tarjan's algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph.
  
- **Auxiliary Space Complexity** : The auxiliary space complexity is `O(V + E)`, where V is the number of vertices and E is the number of edges in the graph. This space is utilized for maintaining the `vis`, `dis`, `low`, and `ans` vectors.

### Code (C++)
```cpp
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
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.