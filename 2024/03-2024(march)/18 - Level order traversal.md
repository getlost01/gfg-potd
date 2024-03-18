## 18. Level order traversal
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/level-order-traversal/1)

### My Approach
- I performed a level order traversal of the binary tree using BFS approach.
- We start by pushing the root node into the queue.
- Then, we iterate while the queue is not empty:
    - Pop the front node from the queue and push its data into the output vector.
    - If the popped node has a left child, push it into the queue.
    - If the popped node has a right child, push it into the queue.
- Repeat until all nodes are traversed.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, where N is the number of nodes in the binary tree. This is because we visit each node once.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N)`, where N is the number of nodes in the binary tree.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> levelOrder(Node* root) {
        queue<Node*> q;
        vector<int> out;
        
        if(root == nullptr)
            return out;
        
        q.push(root);
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            out.push_back(front->data);
            
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.