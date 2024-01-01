## 17. Transitive closure of a Graph
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

This is the standard Floyd-Warshall graph problem for finding the transitive closure of a graph.
- Initialize a transitive closure matrix with the given graph
- Set all diagonal elements to 1
- Use the Floyd-Warshall algorithm to compute the transitive closure by considering all pairs of vertices and updating the matrix based on the existence of a path between them through a third vertex.

For better understanding, refer to the following video: [Floyd-Warshall Algorithm](https://www.programiz.com/dsa/floyd-warshall-algorithm)

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N^3)`, where `N` is the number of vertices in the graph
- **Auxiliary Space Complexity**: `O(N^2)` is the number of vertices in the graph

### Code (C++)
```cpp
class Solution {
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<vector<int>> transitive(N, vector<int>(N, 0));

        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                transitive[i][j] = graph[i][j];
                if (i == j)
                {
                    transitive[i][j] = 1;
                }
            }
        }

        for (int k=0; k<N; k++)
        {
            for (int i=0; i<N; i++)
            {
                for (int j=0; j<N; j++)
                {
                    if (transitive[i][k] && transitive[k][j])
                    {
                        transitive[i][j] = 1;
                    }
                }
            }
        }

        return transitive;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
