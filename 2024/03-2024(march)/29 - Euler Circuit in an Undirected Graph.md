## 29. Euler Circuit in an Undirected Graph
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1)

### My Approach
- Create an unordered map deg to store the degree of each vertex.
- Iterate through each vertex i from 0 to v-1:
  - Set the degree of vertex i as the size of its adjacency list.
- Iterate through each key-value pair (vertex, degree) in the deg map:
  - Check if the degree of the vertex is odd:
    - If it's odd, return false as an Euler circuit cannot exist.
- If no odd degree vertices are found, return true indicating that an Euler circuit exists.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V + E)`, where `V` is the number of vertices and E is the number of edges.
- **Auxiliary Space Complexity**: `O(V)`, where `V` is the number of vertices.

### Code (C++)
```cpp
class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    unordered_map<int, int>deg;
        for (int i=0;i<v;i++) 
            deg[i]=adj[i].size();
        for (auto& kv : deg)
        {
            if (kv.second%2!=0)
                return false;
        }
        return true;
	}

};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
