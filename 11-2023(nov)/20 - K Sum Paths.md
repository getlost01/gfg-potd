## 20. K Sum Paths
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-sum-paths/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
To solve the problem,
- I traverse the tree using a recursive depth-first search (DFS) approach. 
- I maintain a running sum as I traverse the tree and use an unordered map to keep track of the cumulative sums encountered so far. 
- At each node, I check if the complement of the current sum (i.e., `currSum - k`) exists in the map. 
	- If it does, it means there is a path with the required sum, and I update the result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the tree.
- **Auxiliary Space Complexity**: `O(N)`, due to the usage of an unordered map for tracking sums.

### Code (C++)
```cpp
class Solution {
public:
    int traversal(Node *root, unordered_map<int, int>& mp, int& k, int sum) {
        if (!root) return 0;
        
        int res = 0;
        int currSum = sum + root->data;
        
        if (mp.find(currSum - k) != mp.end()) 
            res += mp[currSum - k];
            
        mp[currSum]++;
        
        res += traversal(root->left, mp, k, currSum);
        res += traversal(root->right, mp, k, currSum);
        
        mp[currSum]--;
        return res;
    }

    int sumK(Node *root, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        return traversal(root, mp, k, 0);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.