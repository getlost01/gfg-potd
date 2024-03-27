## 27. Find shortest safe route in a matrix
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1)

### My Approach
- We start by identifying all the bomb locations in the matrix and mark their adjacent cells as unsafe.
- Then, we perform a breadth-first search (BFS) starting from all the cells in the first column, considering them as starting points. During BFS traversal, we mark visited cells as unsafe and continue BFS.
- We repeat BFS until we reach the last column or there are no more reachable safe cells.
- The shortest path will be the minimum number of steps required to reach any cell in the last column from the starting points.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(M * N)`, where M is the number of rows and N is the number of columns in the matrix. This complexity arises from the BFS traversal.
- **Auxiliary Space Complexity**: `O(M * N)`, where M is the number of rows and N is the number of columns in the matrix. This space is required for the queue used in BFS and for marking visited cells.

### Code (C++)
```cpp
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int findShortestPath(vector<vector<int>> &mat){
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        
        vector<pair<int, int>> bombs;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == 0) 
                    bombs.push_back({i, j}); 
                    
        for(auto itr : bombs){
            for(int d = 0; d < 4; ++d){
                int x = itr.first + dx[d];
                int y = itr.second + dy[d];
                if(x >= 0 && y >= 0 && x < m && y < n)
                    mat[x][y] = 0;
            }
        }
        
        queue<pair<int,int>> q;
        for(int i = 0; i < m; ++i) 
            if(mat[i][0]){ 
                mat[i][0] = 0;
                q.push({i, 0});
            }
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(f.second == n-1) 
                    return ans;
                    
                for(int d = 0; d < 4; ++d){
                    int x = f.first + dx[d];
                    int y = f.second + dy[d];
                    if(x >= 0 && y >= 0 && x < m && y < n && mat[x][y]){
                        mat[x][y] = 0;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.