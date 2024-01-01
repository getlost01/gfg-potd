## 01. Check whether BST contains Dead End
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
In a Binary Search Tree (BST), we can figure out if there's a dead end by going through the nodes in sorted order during an in-order traversal. Here's how it works:

- To do this, I keep two lists: `arr` for all the nodes in order and `leaf` for the leaf nodes.
- After getting all the nodes and leaves in sorted order by inorder traverse, I go through each node and check if its adjacent leaves are just one less or one more.
- When a node doesn't have any children (meaning it's a leaf) and its value is only one more or one less than its parent, that's a dead end.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(N), where N is the number of nodes in the BST.
- **Auxiliary Space Complexity**: O(N), where N is the number of nodes in the BST.

### Code (C++)
```cpp
class Solution{
  public:
    vector<int> arr, leaf;
    
    void inorder(Node* node){
        if(!node)
            return;
        
        inorder(node->left);
        arr.push_back(node->data);
        if(!node->left && !node->right)
            leaf.push_back(node->data);
        inorder(node->right);
    }
    
    bool isDeadEnd(Node *root)
    {
        arr = {0};  // Initialize with a 0 value to handle the edge case of root being 1.
        leaf = {};
        inorder(root);
        
        int j = 0;
        for(int i = 1; i < arr.size() && j < leaf.size(); ++i){
            if(arr[i] == leaf[j]){
                if(arr[i-1] == leaf[j] - 1 && arr[i+1] == leaf[j] + 1)
                    return true;
                ++j;
            }
        }
        
        return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.