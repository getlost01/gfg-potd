## 02. Shortest Source to Destination Path

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1)

### My Approach

To find the shortest path from the source (0,0) to the destination (X,Y) in a grid, we can use a Breadth-First Search (BFS) algorithm. The idea is to start from the source and explore all possible paths in the grid until we reach the destination. We keep track of the steps taken to reach each cell and return the minimum steps required to reach the destination.

- Initialize a queue for BFS traversal.
- Mark the source cell (0,0) as visited and enqueue it with steps = 0.
- While the queue is not empty, do the following:
   - Dequeue a cell from the queue and extract its coordinates (x, y) and the steps taken so far.
   - If the dequeued cell is the destination (X, Y), update the result with the minimum steps obtained so far.
   - Explore all four adjacent cells (up, down, left, right) from the current cell and enqueue the valid and unvisited cells with steps + 1.
- If the destination is not reached, return -1, otherwise, return the minimum steps.

### Time and Auxiliary Space Complexity

- **Time Complexity**: Since BFS algorithm explores all reachable cells once, so the time complexity is `O(n * m)`, where 'n' is the number of rows and 'm' is the number of columns in the grid.
- **Auxiliary Space Complexity**: `O(n * m)` as we use a queue to store cells during BFS traversal, and the vis vector to mark visited cells.

### Code (C++)

```cpp
class Solution {
public:
    struct trip {
        int x, y, steps;
    };

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool isValid(int& nx, int& ny, int& n, int& m) {
        return (nx >= 0 && nx < n && ny >= 0 && ny < m);
    }

    int shortestDistance(int n, int m, vector<vector<int>> a, int X, int Y) {
        queue<trip> q;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        q.push({0, 0, 0});
        vis[0][0] = 1;
        int out = INT_MAX;

        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int steps = q.front().steps;
            q.pop();

            if (x == X && y == Y)
                out = min(out, steps);

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isValid(nx, ny, n, m) && a[nx][ny] && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny, steps + 1});
                }
            }
        }
        return (out == INT_MAX) ? -1 : out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.