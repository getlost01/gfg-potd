## 28. Lowest Common Ancestor in a BST

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1)

### My Approach

To find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST),  I used the property of a BST where the left subtree contains nodes with values less than the root node, and the right subtree contains nodes with values greater than the root node. Starting from the root, we can traverse down the tree until we find a node whose value lies between the given two nodes, n1 and n2. This node would be the LCA.

**The steps involved in our approach are as follows:**
1. Start from the root node.
2. Compare the data of the current node with the values of `n1` and `n2`.
3. If both `n1` and `n2` are smaller than the current node's value, move to the left subtree and repeat step 2.
4. If both `n1` and `n2` are greater than the current node's value, move to the right subtree and repeat step 2.
5. If the current node's value lies between `n1` and `n2` (inclusive), it is the LCA.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(h)`, where `h` is the height of the BST. In the worst case, the height of the BST can be `O(n)`, but in a balanced BST, it will be `O(log n)`.

- **Auxiliary Space Complexity**: `O(h)` as well, due to the recursive calls made during the traversal. In the worst case, it can be `O(n)` if the tree is skewed, but in a balanced BST, it will be `O(log n)`.

### Code (C++)
```cpp
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            int curr = root->data;
            if(curr > n1 && curr > n2)
                return LCA(root->left, n1, n2);
                
            if(curr < n1 && curr < n2)
                return LCA(root->right, n1, n2);
            
            return root;
        }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.