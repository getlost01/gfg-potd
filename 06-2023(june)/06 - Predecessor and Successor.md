## 06. Finding Predecessor and Successor in a Binary Search Tree

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1)

### My Approach

To find the predecessor and successor of a given key in a binary search tree (BST), I have used the following approach:

- Initialize the predecessor (`pre`) and successor (`suc`) pointers as `nullptr`.
- Define a depth-first search (DFS) function `dfs` that takes the current node as input.
- Within the `dfs` function, check if the current node's key is less than the target key (`key`). If it is, update the predecessor (`pre`) if it is `nullptr` or if its key is less than the current node's key.
- Similarly, if the current node's key is greater than the target key, update the successor (`suc`) if it is `nullptr` or if its key is greater than the current node's key.
- Recursively call the `dfs` function for the left and right subtrees of the current node.
- Handle the case when the current node has both left and right children. If both children have keys less than the target key or both have keys greater than the target key, continue the search in the appropriate subtree. Otherwise, call the `dfs` function for both subtrees to handle the case where the predecessor and successor are in different subtrees.
- Finally, call the `dfs` function with the root of the BST to find the predecessor and successor.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(H)`, where `H` is the height of the BST. In the worst case, the BST is skewed, resulting in a time complexity of `O(N)`, where `N` is the number of nodes in the BST. However, on average, for a balanced BST, the time complexity is `O(log N)`.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` since we are not using any extra space that scales with the input.

### Code (C++)

```cpp
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre = suc = nullptr;
        
        function<void(Node*)> dfs = [&](Node * current) {
            if(current -> key < key){
                if(pre == nullptr or pre -> key < current -> key)
                    pre = current;
            }
            
            if(current -> key > key){
                if(suc == nullptr or suc -> key > current -> key)
                    suc = current;
            }
            
            if(current -> left != nullptr and current -> right != nullptr){
                if(current -> left -> key < key and current -> right -> key < key)
                    dfs(current -> right);
                else if(current -> left -> key > key and current -> right -> key > key)
                    dfs(current -> left);
                else{
                    dfs(current -> left);
                    dfs(current -> right);
                }
                
            }
            else if(current -> left != nullptr)
                dfs(current -> left);
            else if(current -> right != nullptr)
                dfs(current -> right);
        };
        
        dfs(root);
    }
};

```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.