## 30. Inorder Successor in BST

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1)

### My Approach

To find the inorder successor of a given node `x` in a Binary Search Tree (BST), we can perform an inorder traversal of the BST while keeping track of the previously visited node (`prev`). When we encounter the node `x`, the next node visited in the inorder traversal will be its inorder successor.

### Explanation

- We start by defining a helper function `inorder` that performs the inorder traversal and finds the inorder successor of the given node `x`.
- In the `inorder` function, we recursively traverse the BST in an inorder fashion (left subtree, current node, right subtree).
- During the traversal, we compare each previous node with the given node `x`.
- If we find the node `x`, we set the `succ` pointer to the current node `root`(which will be the inorder successor).
- Before moving to the next node in the inorder traversal, we update the `prev` pointer to the current node.
- Once the traversal is complete, we return the `succ` pointer, which will hold the inorder successor of `x`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of the `inorder` function is `O(N)`, where `N` is the number of nodes in the BST.

- **Auxiliary Space Complexity**: The auxiliary space complexity of the `inorder` function is `O(H)`, where `H` is the height of the BST. 

### Code (C++)

```cpp
class Solution {
public:
    Node* succ;

    void inorder(Node* root, Node* x, Node* &prev) {
        if (!root)
            return;
        
        inorder(root->left, x, prev);

        if (prev == x)
            succ = root;
        
        prev = root;
        inorder(root->right, x, prev);
    }

    Node* inOrderSuccessor(Node* root, Node* x) {
        Node* prev = NULL;
        succ = NULL;
        inorder(root, x, prev);
        return succ;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.