## 18. Eventual Safe States
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/eventual-safe-states/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

- Initialize empty vectors result and state (size V) for safe nodes and node states.
- Iterate through each node in the graph.
- For each node, call the isSafe function.
- In isSafe function:
  - If the node is in state 1, return false (cycle detected).
  - If the node is in state 2, return true (visited and safe).
  - Mark the node as visiting (state 1).
  - Recursively explore neighbors, calling isSafe on them.
  - If any neighbor is not safe, return false.
  - Mark the current node as visited and safe (state 2) and return true.
- If isSafe returns true for a node, add it to result.
- After processing all nodes, sort result in ascending order.
- Return the sorted result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V+E)`, where `V` is the number of vertices and `E` is the number of edges in the graph
- **Auxiliary Space Complexity**: `O(V)`, where `V` is the number of vertices

### Code (C++)
```cpp
class Solution
{
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> result;
        vector<int> state(V, 0);

        for (int i=0; i<V;i++)
        {
            if (isSafe(i, adj, state, result))
            {
                result.push_back(i);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }

    bool isSafe(int node, vector<int> adj[], vector<int>& state, vector<int>& result)
    {
        if (state[node] == 1)
        {
            return false;
        }
        if (state[node] == 2)
        {
            return true;
        }

        state[node] = 1;
        for (int neighbor : adj[node])
        {
            if (!isSafe(neighbor, adj, state, result))
            {
                return false;
            }
        }
        state[node] = 2;
        return true;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
