## 14. Find Common Nodes in two BSTs
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

I have implemented a solution that involves an in-order traversal of the first BST (root1) and for each visited node, I check if that node's data exists in the second BST (root2) by performing a search operation. If it exists in the second BST, I add it to the `out` vector.

Here are the steps:

1. Initialize an empty vector `out` to store the common nodes.
2. Perform an in-order traversal of the first BST (root1) and, for each visited node:
   - Check if that node's value exists in the second BST (root2) by calling the `find` function.
   - If the value is found in the second BST, add it to the `out` vector.
3. Return the `out` vector containing the common nodes.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(N1.log(N2))`, where `N1`and `N2` are the number of nodes in `root1` and `root2` respectively. This is because we visit each node in both trees once during the `inorder` traversal.

- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(H1 + H2)`, where `H1` and `H2`  is the height of both trees in the recursion stack.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> out;

    bool find(Node* node, int x) {
        if (!node)
            return false;

        if (node->data == x)
            return true;

        if (node->data > x)
            return find(node->left, x);

        return find(node->right, x);
    }

    void inorder(Node* root1, Node* root2) {
        if (!root1)
            return;

        inorder(root1->left, root2);
        if (find(root2, root1->data))
            out.push_back(root1->data);
        inorder(root1->right, root2);
    }

    vector<int> findCommon(Node* root1, Node* root2) {
        inorder(root1, root2);
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.