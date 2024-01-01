## 22. Symmetric Tree
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/symmetric-tree/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To check if a binary tree is symmetric, I recursively compare the left subtree of the root with the right subtree. The comparison is done by checking if the data of the current nodes are the same and if the left subtree of the left node is symmetric to the right subtree of the right node, and vice versa.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the tree.
- **Auxiliary Space Complexity**: `O(h)`, where `h` is the height of the tree (recursive stack space).

### Code (C++)
```cpp
class Solution {
public:
    bool checkSymmetric(Node* first, Node* second) {
        if (!first && !second)
            return true;

        if (first && second && first->data == second->data)
            return checkSymmetric(first->left, second->right) && checkSymmetric(first->right, second->left);

        return false;
    }

    bool isSymmetric(struct Node* root) {
        if (!root)
            return true;
        return checkSymmetric(root->left, root->right);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.