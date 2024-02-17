## 18. Sum of leaf nodes in BST
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1)

### My Approach
- Implement a recursive function to traverse the BST in an inorder fashion (left, root, right).
- During the traversal, check if the current node is a leaf node (both left and right children are nullptr).
- If it's a leaf node, add its data value to the sum (ans).
- Recursively call the function on the left and right subtrees.
- Initialize the sum (ans) to zero before starting the traversal.
- Return the final sum after the traversal.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`, where `N` is the number of nodes in the Binary Search Tree.
- **Auxiliary Space Complexity** : `O(H)`, where `H` is the height of the Binary Search Tree.

### Code (C++)
```cpp
class Solution
{
    public:
        int ans=0;
        void func(Node* root)
        {
            if (root!=nullptr)
            {
                func(root->left);
                if (!root->right && !root->left)
                    ans+=root->data;
                func(root->right);
            }
        }
        int sumOfLeafNodes(Node *root )
        {
            ans=0;
            func(root);
            return ans;
        }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
