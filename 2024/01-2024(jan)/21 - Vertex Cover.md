## 21. Vertex Cover
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/vertex-cover/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach
I approached this problem using a recursive method to explore all possible combinations of vertices in the vertex cover. Here are the steps:

- I implemented a recursive function `solve` to explore different combinations of vertices.
- Inside the `solve` function, I checked if the current combination is a valid vertex cover by iterating through the edges.
- I used bitwise operations to manipulate the mask to represent the vertices included in the cover.
- I kept track of the minimum vertex cover size using the variable `out`.
- Finally, I invoked the `solve` function with the initial parameters in the `vertexCover` method.


### Time and Auxiliary Space Complexity
- **Time Complexity**: Exponential, `O(2^n)`, where n is the number of vertices.
- **Auxiliary Space Complexity**: `O(n)`, where n is the number of vertices. (This is the maximum depth of the recursive call stack)

### Code (C++)
```cpp
class Solution {
public:
    void solve(int i, int bits, int n, int m, vector<pair<int, int>>& edges, int &out) {
        if (i > n) {
            for (int i = 0; i < m; i++) {
                if (!((1 << (edges[i].first - 1) & bits) != 0 || (1 << (edges[i].second - 1) & bits) != 0)) {
                    return;
                }
            }
            out = min(out, __builtin_popcount(bits));
            return;
        }
        solve(i + 1, bits, n, m, edges, out);
        solve(i + 1, bits | 1 << (i - 1), n, m, edges, out);
    }

    int vertexCover(int n, vector<pair<int, int>> &edges) {
        int out = INT_MAX;
        int m = edges.size();
        solve(1, 0, n, m, edges, out);
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.