## 03. Check if Tree is Isomorphic

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1)

### My Approach

To check if two trees are isomorphic, let's recursively compare the following:
- If both trees are empty, they are isomorphic so return true (our base case).
- If both trees are not empty and their root nodes have the `same` value, we have two possibilities:
  - Trees are isomorphic when (node's children were not flipped):
    - The left subtrees of both trees are isomorphic.
    - The right subtrees of both trees are isomorphic.
  - Trees are isomorphic when (node's children were flipped):
    - The left subtree of the first tree is isomorphic to the right subtree of the second tree.
    - The right subtree of the first tree is isomorphic to the left subtree of the second tree.
- If none of the above possibilities meet our criteria, then return false.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm visits every node in both trees once, so the time complexity is `O(N)`, where `N` is the number of nodes in the tree.
- **Auxiliary Space Complexity**: The recursion stack can go as deep as the height of the tree, so the space complexity is `O(H)`, where `H` is the height of the tree.

### Code (C++)
```cpp
class Solution {
public:
    bool isIsomorphic(Node *root1, Node *root2) {
        if (!root1 && !root2)
            return true;

        if (root1 && root2 && root1->data == root2->data) {
            bool isFlip = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
            bool notFlip = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
            return isFlip || notFlip;
        }

        return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.