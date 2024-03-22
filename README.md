## GFG Problem Of The Day

### Today - 22 March 2024
### Que - Diagonal sum in binary tree
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1)

### My Approach
- Define a function diagonalSum that takes the root of a binary tree as input.
- Initialize an empty vector ans to store diagonal sums.
- Implement a Depth-First Search (DFS) function dfs using a lambda function:
  - Traverse the tree recursively.
  - Maintain the current diagonal level.
  - At each node:
    - Update the sum of the current diagonal level in ans.
    - Recur for the left child with cur + 1 as the diagonal level.
    - Recur for the right child with the same diagonal level cur.
- Invoke dfs with the root node and diagonal level 0.
- Return the ans vector containing diagonal sums.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, where N is the number of nodes in the binary tree.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N)`, where N is the number of nodes in the binary tree.

### Code (C++)
```cpp
class Solution {
  public:
    vector<int> diagonalSum(Node* root)
    {
        vector<int> ans;
        function<void(Node *, int)> dfs = [&](Node * node, int cur)
        {
            if(!node)
                return;
            if(cur==ans.size())
                ans.push_back(node -> data);
            else ans[cur] += node -> data;
            dfs(node->left, cur+1);
            dfs(node->right, cur);
        };
        dfs(root, 0);
        return ans;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

