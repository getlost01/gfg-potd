## 08. Binary Tree to BST

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1)

### My Approach

I solved this problem by utilizing the BST property, where the inorder traversal of the tree results in sorted values. In this context, I reversed this process by:

- First obtaining the inorder order of the binary tree.
- Sorting the values of the binary tree.
- Subsequently updating the binary tree with the sorted values.

Here are the steps to do so:

- Conduct an in-order traversal of the binary tree to obtain the nodes in inorder order.
- Store these nodes in a `nodes` vector and also collect the binary tree values in a `values` vector.
- Sort the `values` vector to arrange the values in ascending order.
- Assign these sorted `values` to the corresponding `nodes` in the vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(NlogN)` (due to sorting), where N is the number of nodes in the binary tree.
- **Auxiliary Space Complexity**: `O(N)` (for the vector to store nodes).

### Code (C++)

```cpp
class Solution {
public:
    void inorder(Node *root, vector<Node*>& nodes) {
        if (!root)
            return;

        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    Node *binaryTreeToBST(Node *root) {
        vector<Node*> nodes;
        inorder(root, nodes);
        vector<int> values;
        
        for (auto node : nodes)
            values.push_back(node->data);

        sort(values.begin(), values.end());

        for (int i = 0; i < nodes.size(); ++i)
            nodes[i]->data = values[i];

        return root;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.