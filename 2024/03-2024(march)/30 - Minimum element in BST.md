## 30. Minimum element in BST
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1)

### My Approach
- Start from the root node.
- Traverse towards the left child of the current node until a leaf node is reached (the node with no left child).
- Return the value of the leaf node, which represents the minimum value in the binary search tree.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(H)`, where `H` is the height of the binary search tree.
- **Auxiliary Space Complexity**: `O(1)`, since the space used is independent of the input size.

### Code (C++)
```cpp
class Solution {
public:   
    int minValue(Node* root)
    {
        if (!root)
            return -1;
        if (root->left)
        {
            root=root->left;
            minValue(root);
        }
        else return root->data;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
