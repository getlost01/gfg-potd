## 05. Print adjacency list

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1)

### My Approach

A basic question with a direct approach:

- I'm creating an adjacency list of a 2D vector to represent the graph.
- I iterate through the given edges and `push` them to the adjacency list, ensuring to push vertices from both directions since it's an undirected graph.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(E)`, where `E` is the number of edges in the graph.
- **Auxiliary Space Complexity** : `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.

### Code (C++)
```cpp
class Solution {
public:
    vector<vector<int>> printGraph(int V, vector<pair<int,int>> edges) {
        vector<vector<int>> adjList(V);
        for(auto edge: edges){
            int u = edge.first;
            int v = edge.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.