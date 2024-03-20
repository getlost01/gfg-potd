## GFG Problem Of The Day

### Today - 20 March 2024
### Que - Sum of nodes on the longest path from root to leaf node
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1)

### My Approach
- Implement Depth First Search (DFS) to traverse the binary tree.
- At each node, calculate the sum and length of the longest path from the root to a leaf node.
- Maintain a pair of integers representing the sum and length of the longest path encountered so far.
- Compare the longest paths from the left and right subtrees. If they have the same length, choose the path with the maximum sum.
- Update the sum and length of the current longest path based on the chosen subtree.
- Recursively compute the sum and length for each subtree.
- Finally, return the sum of nodes along the longest path from the root to any leaf node.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, where N is the number of nodes in the binary tree.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(H)`, where H is the height of the binary tree

### Code (C++)
```cpp
class Solution
{
    public:
    function<pair<int,int>(Node *)>dfs=[&](Node* node)->pair<int,int>
    {
        if(!node)
            return {0, 0};
        pair<int,int>left=dfs(node->left);
        pair<int,int>right=dfs(node->right);
        pair<int,int>ans;
        if(left.second>right.second)
            ans=left;
        else if(right.second>left.second)
            ans=right;
        else
        {
            ans.first=max(left.first, right.first);
            ans.second=left.second;
        }
        ans.first+=(node->data);
        ans.second++;
        return ans;
    };
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        return dfs(root).first;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

