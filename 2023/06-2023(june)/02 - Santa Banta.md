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

class Solution{
public:
    int dfs(int n, int m, vector<vector<int>> &g,vector<bool>& vis,int node){
        int out = 1;
        vis[node] = 1;
        for(auto i: g[node]){
            if(!vis[i]){
                out += dfs(n,m,g,vis,i);
            }
        }
        return out;
    }

  
    vector<int> kPrime;
    void precompute(){
        vector<int> isPrime(1e6+1, true);
        isPrime[0]=false;
        isPrime[1]=false;
        for (int i=2;i<=1e6+1;++i){
            if(isPrime[i]==true){
                kPrime.push_back(i);
                for (int j=2*i;j<=1e6+1;j+=i){
                    isPrime[j]=false;
                }
            }
        }
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        vector<bool> vis(n+1,0);
        int out = -1;
        for(int i = 1;i<=n;++i){
            if(!vis[i]){
                out = max(out,dfs(n,m,g,vis,i));
            }
        }
        if(out>1){
            out = kPrime[out-1];
        }else out = -1;
        return out;
    }
};
```
### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
