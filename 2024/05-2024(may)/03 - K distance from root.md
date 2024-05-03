## 03. K distance from root
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-distance-from-root/1)

### My Approach
- If root is null, return.
- If k equals 0, push the data of the current root node into the ans vector and return.
- Recursively call traverse function for the left child of root with k-1.
- Recursively call traverse function for the right child of root with k-1.
- Clear the ans vector.
- Call traverse function with the root node and distance k.
- Return the ans vector containing nodes at distance k from the root.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the tree.
- **Auxiliary Space Complexity**: `O(H)`, where `H` is the height of the tree.

### Code (C++)
```cpp
class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> ans;

    void traverse(struct Node *root, int k)
    {
        if(!root)
            return;
        if(k == 0)
        {
            ans.push_back(root->data);
            return;
        }
        traverse(root->left, k-1);
        traverse(root->right, k-1);
    }

    vector<int> Kdistance(struct Node *root, int k) 
    {
        ans.clear();
        traverse(root, k);
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
