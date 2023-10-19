## 19. Level of Nodes
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

- Start a BFS traversal from node 0 in the graph.
- Use a queue to keep track of nodes to visit and a vector to store the level of each node.
- For each node visited in the BFS, explore its adjacent nodes, and mark them as visited while updating their levels.
- Continue the BFS until all reachable nodes are visited or until the queue is empty.
- If the target node X is visited, return its level. If it's not visited, return -1.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V + E)`, where `V` is the number of nodes (vertices) and `E` is the number of edges in the graph.
- **Auxiliary Space Complexity**: `O(V)`, where `V` is the number of nodes.

### Code (C++)
```cpp
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
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
