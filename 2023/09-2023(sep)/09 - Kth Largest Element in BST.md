## 09. Kth Largest Element in BST

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1)

### My Approach

To find the kth largest element in a Binary Search Tree (BST), we can perform a modified inorder traversal. 
- The idea is to initiate the traversal from the right subtree, then proceed to the root, and finally explore the left subtree. This order of traversal provides us with the elements in descending order.
- During this traversal, we maintain a count of the kth largest element by decrementing k for each visited node. When k reaches zero, we have identified the kth largest element.

Here are the steps:

- Begin a modified inorder traversal, starting from the right subtree.
- Decrement `k` for each visited node.
- When` k` reaches zero, record the data of the current node as the answer.
- Continue the traversal into the left subtree.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(N)`, where `N` is the number of nodes in the BST.

- **Auxiliary Space Complexity**: The space complexity is `O(H)` due to the recursion stack, where H is the height of the BST.

### Code (C++)
```cpp
class Solution
{
public:
    void modifiedInorder(Node* root, int &k, int &ans){
        if(!root)
            return;
        
        modifiedInorder(root->right, k, ans);
        --k;
        if(!k)  ans = root->data;
        modifiedInorder(root->left, k,  ans);
    }
    
    int kthLargest(Node *root, int k)
    {
        int ans;
        modifiedInorder(root, k, ans);
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.