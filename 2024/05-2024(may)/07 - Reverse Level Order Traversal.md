## 07. Reverse Level Order Traversal
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1)

### My Approach
For this problem, I've used a queue to perform a level-order traversal starting from the root node. However, instead of adding elements to the result vector in the order they are encountered, I've stored them in a temporary vector for each level. After processing each level, I've inserted the elements of that level into the beginning of the result vector, effectively reversing the order of levels.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, where N is the number of nodes in the tree.
- **Auxiliary Space Complexity**: The auxiliary space complexity is O(N), where N is the number of nodes in the tree. This is because we use a queue to store nodes, and in the worst case, the queue can contain all nodes at the last level of the tree.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> out;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> lvl;
            while (sz--) {
                Node* node = q.front();
                q.pop();
                lvl.push_back(node->data);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            out.insert(out.begin(), lvl.begin(), lvl.end());
        }

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.