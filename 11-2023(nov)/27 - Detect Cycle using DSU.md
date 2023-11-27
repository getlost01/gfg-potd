## 27. Detect Cycle using DSU
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
I used the Disjoint Set Union (DSU) data structure to detect cycles in an undirected graph. The steps are outlined as follows:

- **Step 1:** Initialize DSU data structure.
- **Step 2:** Iterate through each vertex in the graph.
- **Step 3:** For each vertex, iterate through its adjacent vertices.
- **Step 4:** If the current vertex and its adjacent vertex belong to the same set, there is a cycle. Merge the sets and return true.
- **Step 5:** If the sets are different, perform the union operation.
- **Step 6:** Continue the process for all vertices.
- **Step 7:** If a cycle is found during the process, return true. Otherwise, return false.

For a clearer explanation of the solution, please check this [solution](https://www.geeksforgeeks.org/detect-cycle-in-graph-using-dsu/).

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.
- **Auxiliary Space Complexity**: `O(V)` for DSU data structure.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> dsu;
    vector<bool> vis;
    vector<set<int>> g;

    int findDSU(int p) {
        if (dsu[p] < 0)
            return p;
        return dsu[p] = findDSU(dsu[p]);
    }

    void merge(int x, int y) {
        if (dsu[x] > dsu[y])
            swap(x, y);

        dsu[x] += dsu[y];
        dsu[y] = x;
    }

    bool dfs(int node, int par) {
        bool isCycle = false;
        vis[node] = true;

        for (auto child : g[node]) {
            if (child != par) {
                int x = findDSU(node);
                int y = findDSU(child);

                if (x == y)
                    return true;

                merge(x, y);
                isCycle = isCycle || dfs(child, node);
            }
        }

        return isCycle;
    }

    int detectCycle(int V, vector<int> adj[]) {
        dsu = vector<int>(V, -1);
        vis = vector<bool>(V, false);
        g = vector<set<int>>(V);

        for (int i = 0; i < V; i++) {
            for (auto x : adj[i])
                g[i].insert(x);
        }

        bool isCycle = false;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                isCycle = isCycle || dfs(i, -1);
        }

        return isCycle;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.