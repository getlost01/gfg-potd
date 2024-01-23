## 24. Is it a tree ?
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/is-it-a-tree/1)

### My Approach
- Check if the difference between the number of nodes (n) and edges (m) is exactly 1. If not, it's not a tree.
- Initialize a vector `vis` to keep track of visited nodes.
- Create an adjacency list `graph` based on the given edges.
-  Perform Depth First Search (DFS) starting from node 0 and mark visited nodes.
- Check if all nodes are visited. If any node is unvisited, it's not a tree.

### Time and Auxiliary Space Complexity
- **Time Complexity**: The time complexity of the Depth First Search is `O(n+m)` where n is the number of nodes and m is the number of edges.
- **Auxiliary Space Complexity**: The space complexity is `O(n)` for the visited array and the adjacency list.

### Code (C++)
```cpp
class Solution {
public:
    void dfs(int s, vector<int> graph[], vector<int> &vis)
    {
        vis[s] = 1;
        for (auto i : graph[s])
            if (!vis[i])
                dfs(i, graph, vis);
    }

    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        if ((n - m) != 1)
            return 0;

        vector<int> vis(n, 0), graph[n];

        for (auto i : adj)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        dfs(0, graph, vis);

        for (auto i : vis)
            if (!i)
                return 0;

        return 1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.