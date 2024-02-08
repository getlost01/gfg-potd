## 08. Check if all leaves are at the same level

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/leaf-at-same-level/1)

### My Approach

To solve this problem, I utilize a breadth-first search (BFS) approach. I traverse the tree level by level using a queue. While traversing, I keep track of the level of each leaf node encountered. If at any point I encounter a leaf node with a different level than the previously encountered leaf nodes, I return false indicating that not all leaves are at the same level. Otherwise, if all leaf nodes are found at the same level, I return true.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(n)`, where `n` is the number of nodes in the binary tree. 
  
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(n)`, where `n` is the number of nodes in the binary tree. This is because we are using a queue to perform a level-order traversal of the tree.

### Code (C++)
```cpp
class Solution {
public:
    bool check(Node *root)
    {
        queue<pair<Node*, int>> q; 
        q.push({root,0});
        int firstLeaf = -1;
        
        while(!q.empty()){
            auto node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            
            if(!node->left && !node->right)
            {
                if(firstLeaf == -1)
                    firstLeaf = lvl;
                else if(firstLeaf != lvl) 
                    return false;
            }
            ++lvl;
            if(node->left) 
                q.push({node->left, lvl});
            if(node->right) 
                q.push({node->right, lvl});
        }
        return true;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.