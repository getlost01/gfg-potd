## 19. Level of Nodes
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

For any question that involves determining the level of, by intuition, we have to implement the Breadth-First Search (BFS) algorithm.

To begin, we do a BFS traversal from node 0 within the graph, seeking to determine the level of the specified node X. 

Here is the process:
1. Use a queue to keep track of nodes that need visiting and a vector to record the level of each visited node.
2. For each node visited during the BFS, explore its adjacent nodes, marking them as visited and updating their levels.
3. Continue the BFS until all reachable nodes are visited or until the queue is empty.
4. If the target node `X` is visited, return its level. If it remains unvisited, return `-1`.

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
