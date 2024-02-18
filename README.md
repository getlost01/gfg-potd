## GFG Problem Of The Day

### Today - 18 February 2024
### Que - Sum of leaf nodes in BST
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1)

### My Approach
- If the root is null, it returns 0.
- If the root has no left and right children (i.e., it's a leaf node), it returns the value of that node.
- Otherwise, it recursively calls itself on the left and right subtrees and returns the sum of the results.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`, where `N` is the number of nodes in the Binary Search Tree.
- **Auxiliary Space Complexity** : `O(H)`, where `H` is the height of the Binary Search Tree.

### Code (C++)
```cpp
class Solution {
public:
    int sumOfLeafNodes(Node *root) {
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
            return root->data;
        
        return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

