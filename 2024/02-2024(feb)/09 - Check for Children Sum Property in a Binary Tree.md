## 09. Check for Children Sum Property in a Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/children-sum-parent/1)

### My Approach

1. Base Cases:
- If the root is NULL, return 1.
- If the root is a leaf, return 1.

2. Calculate Left and Right Sums:
- Initialize leftSum and rightSum to 0.
- If the left child exists, set leftSum to its data.
- If the right child exists, set rightSum to its data.

3. Check Sum Property:
- Check if the data of the current node equals the sum of leftSum and rightSum.
- Recursively check the sum property for the left and right subtrees.
- Return 1 if all conditions are met; otherwise, return 0.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(N)`, where `N` is the number of nodes in the binary tree. 
  
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(H)`, where `H` is the height of the binary tree.

### Code (C++)
```cpp
class Solution{
    public:
    int isSumProperty(Node *root)
    {
        if (root==NULL)
            return 1;
        if (root->left==NULL && root->right==NULL)
            return 1;
            
        int leftSum=0, rightSum=0;
        if (root->left!=NULL)
            leftSum=root->left->data;
        if (root->right!=NULL)
            rightSum=root->right->data;
            
        if (root->data==leftSum+rightSum && isSumProperty(root->left) && isSumProperty(root->right))
            return 1;
        return 0;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
