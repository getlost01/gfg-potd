## 28. Sum of Dependencies in a Graph
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph5311/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
In a directed graph, the sum of dependencies is directly the number of edges. So, for this:
- I iterate each vertex and find the sum of its dependencies, which is the size of its adjacency list.
- Adding up all these values gives the total sum of dependencies in the graph.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V)`, where `V` is the vertices.
- **Auxiliary Space Complexity**: `O(1)`, as no extra space is used.

### Code (C++)
```cpp
class Solution {
public:
    int sumOfDependencies(vector<int> adj[], int V) {
        int sum = 0;
        for (int i = 0; i < V; ++i) {
            sum += adj[i].size();
        }
        return sum;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.