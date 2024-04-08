## 02. Santa Banta

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/santa-banta2814/1)

### My Approach

To solve the problem, I have used a depth-first search (DFS) algorithm to find the largest connected component in an undirected graph. Here are the steps I followed:

1. The `dfs` function is implemented to perform the depth-first search. It takes the current node as input and recursively visits all its unvisited neighbors.
2. Within the `dfs` function, I mark the current node as visited and increment the count of the component.
3. Then, for each unvisited neighbor of the current node, I call the `dfs` function recursively.
4. Finally, the `helpSanta` function is implemented to iterate through all the nodes in the graph and find the largest connected component.
5. It initializes a boolean array `vis` to keep track of visited nodes and an integer variable `out` to store the size of the largest connected component.
6. It calls the `dfs` function for each unvisited node, updating `out` with the maximum component size encountered.
7. If `out` is greater than 1, I retrieve the `out-1`th prime number from a precomputed list of prime numbers (`kPrime`) and assign it to `out`. Otherwise, I assign `-1` to `out`.
8. Finally, the function returns the value of `out`.

### Time and Auxiliary Space Complexity

- **Time Complexity**:  The DFS algorithm has a time complexity of `O(V + E)`, where V is the number of vertices and E is the number of edges in the graph. Therefore, the overall time complexity of the algorithm is `O(n + m)`, where n is the number of nodes and m is the number of edges in the graph.
- **Auxiliary Space Complexity**: The auxiliary space complexity of this approach is `O(n`), where n is the number of nodes in the graph. This is due to the space required for the `vis` array and the recursive call stack.

### Code (C++)

```cpp

// Constant defining the maximum size of the array
const int maxn=1000001;

// Array for marking prime numbers
int a[maxn+1];

// Vector for storing prime numbers
vector<int> pl={2};

class Solution{
public:
    // Function to precompute the prime numbers
    void precompute(){
        // Marking all numbers as prime initially
        for(int i=1;i<=maxn;i++)
            a[i]=1;
        
        // Marking 0 and 1 as not prime
        a[0]=a[1]=0;
        
        // Sieve of Eratosthenes algorithm to mark non-prime numbers
        for(int i=2;i*i<=maxn;i++){
            if(a[i]==1){
                for(int j=i*i;j<=maxn;j+=i){
                    a[j]=0;
                }
            }
        }
        
        // Storing all the prime numbers in the vector
        for(int i=3;i<=maxn;i++)
            if(a[i])
                pl.push_back(i);
    }
    
    // Depth-first search function to find the number of reachable nodes in a graph
    int dfs(int i, vector<int> g[], vector<int> &vis){
        // Marking the current node as visited
        vis[i]=1;
        
        // Counter variable to keep track of the number of reachable nodes
        int cnt=1;
        
        // Recursively traversing all the adjacent nodes of the current node
        for(auto x:g[i]){
            if(!vis[x]){
                cnt+=dfs(x, g, vis);
            }
        }
        
        // Returning the total number of reachable nodes
        return cnt;
    }
    
    // Function to help Santa navigate the given graph
    int helpSanta(int n, int m, vector<vector<int>> &g)
    {
        // Initializing the visited array
        vector<int> vis(n+1, 0);
        
        // Creating an adjacency list for the given graph
        vector<int> adj[n + 1];
        for(auto i : g){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        // Variable to store the largest component size
        int lc=0;
        
        // Traversing all the nodes from 0 to n and finding the largest component
        for(int i = 0; i <= n; i++){
            if(!vis[i]){
                lc=max(lc,dfs(i, adj, vis));
            }
        }
        
        // Checking if there is only one component in the graph
        // If yes, returning -1
        if(lc==1)
            return -1;
        
        // Returning the prime number at the (largest component size - 1) index
        return pl[lc-1];
    }
};
```
### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
