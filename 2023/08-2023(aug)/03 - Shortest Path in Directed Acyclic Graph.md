## 03. Shortest Path in Directed Acyclic Graph

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1)

### My Approach

To find the shortest path in a Directed Acyclic Graph (DAG), we can use a variation of Breadth-First Search `(BFS)` algorithm. First, we build a graph representation from the given edges and initialize a `vis` array to keep track of the minimum distance from the source node (node 0 in this case) to all other nodes. We'll use a queue to perform the BFS traversal.

- Create a `graph` representation using an adjacency list to store the nodes and their corresponding weights.
- Initialize a queue `q` and a `vis` array to keep track of minimum distances. Set all distances to `INT_MAX` except for the source node, which is set to 0.
- Push the source node into the queue with distance 0.
- While the queue is not empty, perform the following steps:
   - Dequeue a node and its distance from the queue.
   - For each neighboring node `next` and its weight `w`, update the distance if the path through the current node is shorter than the previously recorded distance.
   - Push the `next` node and its updated distance into the queue.
- Convert the `vis` array. If a node has distance `INT_MAX`, set it to `-1`, as there is no path from the source to that node.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V + E)` time, where `V` is the number of nodes (n) and `E` is the number of edges (m).
- **Auxiliary Space Complexity**: `O(V)`, where `V` is the number of nodes (n) to store the `vis` array and queue.

### Code (C++)

```cpp
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
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.