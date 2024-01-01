## 24. Right View of Binary Tree

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1)

### My Approach

To get the right view of a binary tree, we perform a level order traversal (BFS) and keep track of the last node encountered at each level. The rightmost node at each level will be included in the result vector.

- Perform a level order traversal (BFS) using a queue named `q`. Start by inserting the `root` node into the queue.
- While the queue is not empty, repeat the following steps:
   - Iterate through all the nodes at the current level (the number of nodes currently in the queue, denoted by `sz`):
      - Dequeue the front node from the queue and assign it to the variable `last`.
      - If `last` has a left child, enqueue it into the queue.
      - If `last` has a right child, enqueue it into the queue.
- Once all nodes at the current level have been traversed, record the value of `last->data` in the `out` vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the binary tree.
- **Auxiliary Space Complexity**: `O(W)`, where `W` is the maximum width of the binary tree (number of nodes in the level with the most nodes).

### Code (C++)

```cpp
class Solution {
public:
    vector<int> rightView(Node *root) {
        vector<int> out;
        queue<Node *> q;
        q.push(root);
        Node* last;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                last = q.front();
                q.pop();
                if (last->left)
                    q.push(last->left);
                if (last->right)
                    q.push(last->right);
            }
            out.push_back(last->data);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.