## 29. Euler Circuit and Path
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### The Concept
#### Euler Circuit
An Euler Circuit is a circuit that traverses every edge of a graph exactly once and returns to the starting point. For a graph to have an Euler Circuit, every vertex must have an even degree. The degree of a vertex is the number of edges incident to it.

**Explanation:**
- If all vertices have even degrees, we can traverse every edge, and since each edge contributes to the degree of two vertices, we won't get stuck at any vertex.
- The even degree condition ensures that we can always leave a vertex after entering it, and we can keep traversing until we return to the starting vertex.

#### Euler Path
An Euler Path is a path that traverses every edge of a graph exactly once but may not necessarily return to the starting point. For a graph to have an Euler Path, there should be either 0 or 2 vertices with an odd degree. If there are 0 vertices with odd degree, the Euler Path is closed and becomes an Euler Circuit.

**Explanation:**
- If there are 0 vertices with an odd degree, we can start and end at any vertex, forming a closed Euler Circuit.
- If there are exactly 2 vertices with odd degree, we can start at one of them and end at the other, ensuring that all other vertices have even degrees.

### My Approach
The approach is simple and derived from the fundamental concept of Eulerian circuits and paths. It involves counting the number of vertices with odd degrees:

- **Euler Circuit**: Check if all vertices have even degrees. If this condition holds true, an Euler Circuit exists in the graph. So we return `2` as our answer.

- **Euler Path**: Check if there are exactly two vertices with odd degrees. If this condition is met, an Euler Path exists, and it can be traversed by starting from one of the vertices with an odd degree and ending at the other. So we return `1` as our answer.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V)`, where `V` is the vertices.
- **Auxiliary Space Complexity**: `O(1)`, as no extra space is used.

### Code (C++)
```cpp
class Solution {
public:
    int isEulerCircuit(int v, vector<int> adj[]) {
        int even = 0, odd = 0;
        for (int i = 0; i < v; i++) {
            if (adj[i].size() & 1)
                ++odd;
            else
                ++even;
        }

        return even == v ? 2 : (odd > 0 && odd == 2);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.