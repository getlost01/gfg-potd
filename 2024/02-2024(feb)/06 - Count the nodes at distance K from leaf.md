## 06. Count the nodes at distance K from leaf
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/node-at-distance/1)

### My Approach
I have perform a Depth First Search (DFS) traversal of the tree.
- During the traversal, we'll maintain a map to keep track of whether a node at a certain level has been visited or not.
- Whenever we encounter a leaf node, we'll check if the distance between the current level and the leaf node is equal to K. If it is, and the node at the distance K from the leaf hasn't been visited before, we'll mark it as visited and increment the counter.
- We'll continue this process recursively for the left and right child nodes.

### Time and Auxiliary Space Complexity

- **Time Complexity:** The time complexity of the algorithm is `O(N)`, where `N` is the number of nodes in the tree, since we visit each node once.
- **Auxiliary Space Complexity:** The auxiliary space complexity is `O(N)` due to the usage of the unordered map to store nodes at each level.

### Code (C++)

```cpp
class Solution {
public:
    int cnt;
    
    void dfs(Node* node, int& k, int lvl, unordered_map<int, bool>& mp) {
        if (!node)
            return;
        
        mp[lvl] = false;
        
        if (!node->left && !node->right) {
            if (lvl - k >= 0 && !mp[lvl - k]) {
                mp[lvl - k] = true;
                cnt++;
            }
        }
        
        ++lvl;
        dfs(node->left, k, lvl, mp);
        dfs(node->right, k, lvl, mp);
    }
    
    int printKDistantfromLeaf(Node* root, int k) {
        cnt = 0;
        unordered_map<int, bool> mp;
        dfs(root, k, 0, mp);
        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.