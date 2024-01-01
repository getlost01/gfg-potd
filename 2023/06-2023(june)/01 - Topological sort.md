## 01. Topological sort

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/topological-sort/1)

### My Approach

To solve the problem efficiently, I have implemented the topological sort algorithm using a depth-first search (DFS) approach. Here's a breakdown of the steps involved:

1. Create a stack to store the sorted elements and initialize a vector to keep track of visited nodes.
2. Implement the DFS function, which takes in the number of nodes, an adjacency list, the visited vector, and the current node as parameters.
3. Mark the current node as visited.
4. Iterate through the adjacent nodes of the current node.
5. If an adjacent node has not been visited, recursively call the DFS function on that node.
6. Once all adjacent nodes have been visited, push the current node onto the stack.
7. In the topoSort function, initialize the visited vector with zeros.
8. Iterate through all nodes and call the DFS function on any unvisited nodes.
9. Pop the elements from the stack and store them in the visited vector in reverse order.
10. Finally, return the sorted vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(V + E)`, where `V` represents the number of vertices (nodes) and `E` represents the number of edges in the graph. This complexity arises from traversing all nodes and their adjacent edges during the DFS traversal.

- **Auxiliary Space Complexity**: `O(V)`, where V represents the number of vertices. This complexity is due to the usage of the stack and the visited vector, both of which grow with the number of nodes in the graph.

### Code (C++)

```cpp

class Solution
{
	public:
	stack<int> st;
	void dfs(int n, vector<int> adj[],vector<int>& vis, int node){
	    vis[node] = 1;
	    for(auto i: adj[node]){
	        if(!vis[i]){
	            dfs(n,adj,vis,i);
	        }
	    }
        st.push(node);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int> vis(n,0);
	    for(int i = 0;i<n;++i){
	        if(!vis[i]){
	            dfs(n,adj,vis,i);
	        }
	    }
	    int i = 0;
	    while(!st.empty()){
	        vis[i++] = st.top();
	        st.pop();
	    }
	    return vis;
	}
};

```
### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.