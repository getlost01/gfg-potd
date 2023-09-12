## 06. Mother Vertex

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/mother-vertex/1)

### My Approach

The intuition behind this question is that we need to find a mother vertex in the graph. In partial topological sort, the concept is to arrange the vertices in such a way that the most dependent vertex comes first in the order, and the independent vertices come last. Therefore, the independent vertex is our required mother vertex.

Here is my approach to solving this question:

**Step 1:** Initialize an empty vector called `topo` to store the topologically sorted order and a visited array called `vis` of size `V`.

**Step 2:** Perform a topological sort using DFS traversal, starting from each unvisited vertex. During the DFS, mark visited vertices and push them onto the `topo` vector.

**Step 3:** After completing the DFS traversal, check if the `topo` stack contains all `V` vertices.
- If it does, pick the last vertex, `motherVer`, from the `topo` stack (which will be a potential mother vertex).

**Step 4:** Reset the `vis` array and clear the `topo` stack.

**Step 5:** Perform another DFS starting from `motherVer`.
- If the DFS covers all vertices, return `motherVer` as the mother vertex.

**Step 6:** If the DFS in Step 5 does not cover all vertices, return -1 as there is no mother vertex.

### Example:

Consider a graph with the following adjacency list:
```
0 -> 2, 3
1 -> 0
2 -> 1
3 -> 4
4 ->
```

- After the first DFS traversal, the topological order would be `[1, 4, 3, 2, 0 ]`. Since this includes all vertices, we proceed to step 5.
- In the second DFS starting from vertex `0`, we cover all vertices, so the mother vertex is `0`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The code performs two DFS traversals. The first DFS takes `O(V + E)` time, where `V` is the number of vertices and `E` is the number of edges. The second DFS also takes `O(V + E)` time. Therefore, the total time complexity is O(V + E).
  
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(V)`, where `V` is the number of vertices, for the `vis` and `topo` arrays.

### Code (C++)

```cpp
class Solution {
public:
    void dfs(int i, vector<int> adj[], vector<int>& vis, vector<int>& topo) {
        vis[i] = 1;
        for (auto edge : adj[i]) {
            if (!vis[edge]) {
                dfs(edge, adj, vis, topo);
            }
        }
        topo.push_back(i);
    }
    
    int findMotherVertex(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), topo;
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(i, adj, vis, topo);
            }
        }
        
        if (topo.size() == V) {
            int motherVer = topo.back();
            vis.assign(V, 0);
            topo.clear();
            dfs(motherVer, adj, vis, topo);
            if (topo.size() == V)
                return motherVer;
        }
        
        return -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.