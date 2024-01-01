## 28. Maximum Depth of Binary Tree

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/maximum-depth-of-binary-tree/1)

### My Approach

To find the maximum depth (height) of a binary tree, I have used the following approach:

- I have implemented the Breadth-First Search (BFS) algorithm to traverse all levels of the tree.
- I initialize a `height` variable to keep track of the number of levels in the tree.
- I use a queue (`q`) to perform the BFS traversal. I start by pushing the root node into the queue.
- While the queue is not empty, I process each level by iterating through the elements in the queue.
- For each level, I increment the `height` variable by 1.
- During each level traversal, I remove the front node from the queue and enqueue its left and right child nodes if they exist.
- After processing all the nodes in the current level, I move to the next level by continuing the outer while loop.
- Finally, I return the value of the `height` variable, which represents the maximum depth (height) of the binary tree.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the binary tree. This is because we visit each node once during the BFS traversal.
- **Auxiliary Space Complexity**: `O(M)`, where `M` is the maximum number of nodes in a single level of the binary tree. In the worst case, the last level of the tree can contain `(N/2)` nodes, where N is the total number of nodes. Therefore, the space required for the queue can be `O(N/2)`, which simplifies to `O(N)`.

### Code (C++)

```cpp
class Solution {
public:
    int maxDepth(Node* root) {
        int height = 0;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            ++height;
            
            while (sz--) {
                auto frontNode = q.front();
                q.pop();
                
                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
            }
        }
        
        return height;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.