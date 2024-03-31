## 31. Closest Neighbour in BST
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1)

### My Approach
I used the lower bound logic to solve this problem.
- At each node, we compare the node's value with `n`. 
- If the node's value is less than or equal to `n`, we move to the right subtree as the potential closest neighbor might exist on the right side. 
- Otherwise, we move to the left subtree. We continue this process until we reach a leaf node or a node with a value exactly equal to `n`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(h)`, where h is the height of the BST.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` since we are using only a constant amount of space for recursive calls and variable storage.

### Code (C++)
```cpp
class Solution {
public:
    int findMaxForN(Node* root, int n) {
        if (!root)
            return -1;

        if (root->key <= n)
            return max(root->key, findMaxForN(root->right, n));

        return findMaxForN(root->left, n);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.