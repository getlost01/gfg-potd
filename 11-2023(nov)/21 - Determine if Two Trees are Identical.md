## 21. Determine if Two Trees are Identical
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To determine if two trees are identical, I recursively compare corresponding nodes in both trees. The base cases are:
- If both nodes are `NULL`, they are identical.
- If only one of the nodes is `NULL` or their data is not equal, they are not identical.
Then, I recursively check the left and right subtrees for identity.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`, where `N` is the number of nodes in the tree.
- **Auxiliary Space Complexity** : `O(H)`, where `H` is the height of the tree.

### Code (C++)
```cpp
class Solution {
public:
    bool isIdentical(Node *r1, Node *r2) {
        if (!r1 && !r2) 
            return true;
        
        if (!r1 || !r2 || r1->data != r2->data) 
            return false;
        
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.