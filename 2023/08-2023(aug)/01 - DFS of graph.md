## 01. DFS of graph

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

### My Approach

To perform a Depth-First Search (DFS) of a graph, we start by visiting the starting node and then recursively visit all its adjacent unvisited nodes. We use a recursive function to traverse the graph in a depth-first manner.

Here are the steps of the DFS algorithm:

- Create a function `dfs` that takes the current node, an output vector to store the traversal order, an adjacency list representing the graph, and a visited array to keep track of visited nodes.
-  Add the current node to the output vector to record the traversal order.
- Mark the current node as visited.
- For each unvisited adjacent node of the current node, call the `dfs` function recursively with that node.
- Once we have traversed all nodes reachable from the starting node, the `dfsOfGraph` function will return the output vector containing the DFS traversal order.

### Time and Auxiliary Space Complexity

- **Time Complexity**: In the worst case, it traverses all the nodes and edges, resulting in a time complexity of `O(V + E)`, where `V` is the number of nodes (vertices) and `E` is the number of edges in the graph.
- **Auxiliary Space Complexity**: `O(V)` as we use an additional visited array of size `V` to keep track of visited nodes. Additionally, the output vector to store the traversal order also requires `O(V)` space.

### Code (C++)

```cpp
class Solution {
public:
    void dfs(int i, vector<int>& out, vector<int> adj[], vector<bool>& vis) {
        out.push_back(i);

        for (auto node : adj[i]) {
            if (!vis[node]) {
                vis[node] = true;
                dfs(node, out, adj, vis);
            }
        }
    }

    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> out;
        vector<bool> vis(v, false);

        vis[0] = true;
        dfs(0, out, adj, vis);

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.