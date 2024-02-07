## 07. Min distance between two given nodes of a Binary Tree
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1)

### My Approach
To find the minimum distance between two given nodes in a binary tree, we can traverse the tree recursively. We'll start from the root and recursively search for both nodes. Once we find both nodes, we'll calculate the distance between their lowest common ancestor (LCA) and the nodes. The distance between the LCA and each node can be calculated by counting the number of edges between the LCA and the node. Finally, we'll sum these distances to get the minimum distance between the given nodes.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n), where n is the number of nodes in the binary tree.
- **Auxiliary Space Complexity** : O(h), where h is the height of the binary tree.

### Code (C++)
```cpp
class Solution {
public:
    int ans = 0;

    int solve(Node* root, int a, int b) {
        if (root == NULL || ans > 0) 
            return 0;

        int l = solve(root->left, a, b);
        int r = solve(root->right, a, b);

        if ((root->data == a || root->data == b)) {
            if (l != 0) 
                ans = l;
            else if (r != 0) 
                ans = r;
            else 
                return 1;
        }

        if (l != 0 && r != 0) 
            ans = l + r;
        else if (l != 0) 
            return l + 1;
        else if (r != 0) 
            return r + 1;
        
        return 0;
    }

    int findDist(Node* root, int a, int b) {
        if (a == b) 
            return 0;
        
        solve(root, a, b);
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.