## 11. Check for Balanced Tree

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach

To check if a binary tree is balanced, I use a recursive approach. For each node, I calculate the height of its left and right subtrees, and then check if the absolute difference between these heights is less than or equal to 1. If this condition holds for all nodes in the tree, it is considered balanced.

Here are the steps in my approach:
- If the root is NULL, return true because an empty tree is considered balanced.
- Recursively check if the left subtree is balanced.
- Recursively check if the right subtree is balanced.
- Calculate the height of the left and right subtrees.
- Check if the absolute difference between the heights of the left and right subtrees is less than or equal to 1.
- Update the height of the current node as the maximum of the heights of its left and right subtrees plus 1.
- Return true if both the left and right subtrees are balanced and the current node satisfies the balance condition.


### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, where `N` is the number of nodes in the binary tree. This is because we visit each node once to calculate its height and check the balance condition.

- **Space Complexity**: The space complexity is `O(H)`, where `H` is the height of the binary tree. In the worst case, the space complexity is `O(N)` for a skewed tree, and in the best case, it is `O(log N)` for a balanced tree. This space is used for the recursive call stack.

### Code (C++)

```cpp
class Solution {
public:
    unordered_map<Node *, int> height;

    bool isBalanced(Node *root) {
        if (!root)
            return true;

        bool ok = isBalanced(root->left) && isBalanced(root->right);
        int left = height[root->left];
        int right = height[root->right];

        ok = ok && (abs(left - right) <= 1);
        height[root] = max(left, right) + 1;

        return ok;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.