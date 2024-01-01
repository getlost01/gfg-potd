## 02. Leaf under budget

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/leaf-under-budget/1)

### My Approach

I am using a breadth-first search (BFS) approach to traverse the tree.
- I maintain a queue to keep track of nodes and their corresponding levels.
- As I traverse the tree level by level, I check if a node is a leaf node (both left and right children are null). 
	- If it is a leaf node and the level is greater than the budget (k), I return the count of leaf nodes found so far. 
	- Otherwise, I increment the count and subtract the current level from the budget.
- If the node has children, I push them into the queue with their corresponding levels.

In this solution, as we traverse from level 1 down to there leaf nodes, it naturally addresses our greedy approach to maximize the number of leaf nodes within our budget, providing the desired answers automatically.
### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm visits each node in the tree once, so the time complexity is `O(N)`, where `N` is the number of nodes in the tree.
- **Auxiliary Space Complexity**: The space complexity is `O(W)`, where `W` is the maximum number of nodes at any level in the tree.

### Code (C++)
```cpp
class Solution {
public:
    int getCount(Node *root, int k) {
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        int cnt = 0;

        while (!q.empty() && k > 0) {
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (!node->left && !node->right) {
                if (level > k)
                    return cnt;

                ++cnt;
                k -= level;
            } else {
                if (node->left)
                    q.push({node->left, level + 1});
                if (node->right)
                    q.push({node->right, level + 1});
            }
        }

        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.