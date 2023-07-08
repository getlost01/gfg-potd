## 05. Find the Closest Element in BST

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1)

### My Approach

To find the closest element to a given key (`K`) in a binary search tree (BST), I have used the following approach:

- Traverse the BST while comparing each node's value with the target key (`K`).
- Keep track of the minimum difference (`md`) found so far between the node's value and the target key, as well as the node value (`md_key`) associated with the minimum difference.
- Recursively check the left and right subtrees based on the target key's value compared to the current node's value.
- Update `md` and `md_key` if a closer value is found.
- Finally, return the absolute difference between `md_key` and `K`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the BST. However, on average, for a balanced BST, the time complexity is `O(log N)`.
- **Auxiliary Space Complexity**: `O(1)` since we are not using any extra space that scales with the input.

### Code (C++)

```cpp
class Solution {
public:
    void check(struct Node *node, int k, int &md, int &md_key){
        if (node == NULL)
            return;
     
        if (node->data == k){
            md_key = k;
            return;
        }
     
        if (md > abs(node->data - k)){
            md = abs(node->data - k);
            md_key = node->data;
        }
     
        if (k < node->data)
            check(node->left, k, md, md_key);
        else
            check(node->right, k, md, md_key);
    }
     
    int minDiff(Node *root, int k){
        int md = INT_MAX, md_key = -1;
        check(root, k, md, md_key);
     
        return abs(md_key - k);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.