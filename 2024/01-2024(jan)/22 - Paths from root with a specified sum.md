## 22. Paths from root with a specified sum
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1)

### My Approach
- I used a recursive approach to traverse the tree and find paths with the specified sum.
- For each node, I added its value to the current sum and checked if it equals the target sum.
- If a path with the sum is found, I added it to the result vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity is `O(N)`, where N is the number of nodes in the binary tree. This is because we visit each node exactly once.
- **Auxiliary Space Complexity**: The space complexity is `O(H)`, where H is the height of the tree. In the worst case, the space required for the call stack is the height of the tree.

### Code (C++)
```cpp
class Solution {
public:
    void solve(Node *root, int s, int sum, vector<int> v, vector<vector<int>>& out) {
        if (!root)
            return;
        v.push_back(root->key);
        s += root->key;
        if (s == sum)
            out.push_back(v);
        solve(root->left, s, sum, v, out);
        solve(root->right, s, sum, v, out);
    }

    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<vector<int>> out;
        vector<int> v;
        solve(root, 0, sum, v, out);
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.