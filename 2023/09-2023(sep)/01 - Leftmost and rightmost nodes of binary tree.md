## 01. Leftmost and rightmost nodes of binary tree

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1)

### My Approach

To print the leftmost and rightmost nodes of a binary tree, we can use a level order traversal. 
- We'll traverse the tree level by level using a queue. 
- At each level, we'll keep track of the first and last nodes encountered. 
- Once the level order traversal is complete, we'll have the leftmost and rightmost nodes.

Here are the detailed steps:
- Initialize a queue and push the root node into it.
- While the queue is not empty, do the following:
  - Get the number of nodes at the current level (it's the size of the queue).
  - Initialize variables for the first and last nodes at this level.
  - Iterate through all nodes at this level:
    - Dequeue a node.
    - Update the last node with the dequeued node.
    - If the node has a left child, enqueue it.
    - If the node has a right child, enqueue it.
  - Print the data of the first and last nodes for this level.
- Repeat this process until the queue is empty.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm traverses each node of the binary tree once. Therefore, the time complexity is `O(N)`, where `N` is the number of nodes in the tree.
- **Auxiliary Space Complexity**: The space complexity is `O(W)`, where `W` is the maximum width of the tree (the number of nodes at the widest level).

### Code (C++)

```cpp
class Solution {
public:
    void printCorner(Node *root) {
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            Node* first = q.front();
            Node* last;
            
            while (sz--) {
                last = q.front();
                q.pop();
                if (last->left)
                    q.push(last->left);
                if (last->right)
                    q.push(last->right);
            }
            
            if (first != last)
                cout << first->data << " " << last->data << " ";
            else
                cout << first->data << " ";
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.