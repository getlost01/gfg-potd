## 10. Insert a node in a BST

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1)

### My Approach

To insert a node in a Binary Search Tree (BST), we start at the root and traverse the tree while comparing the data to be inserted with the data in the current node. 
- If the data is less than the current node's data, we move to the left subtree.
- If it's greater, we move to the right subtree. 
- We repeat this process until we find an empty spot to insert the new node.

Here are the steps of my approach:

- If the BST is empty (root is null), create a new node with the given data and make it the root of the tree.
- If the data to be inserted is greater than the current node's data, move to the right subtree. 
	- If the right child of the current node is null, create a new node with the data and make it the right child
	- otherwise, repeat the process recursively with the right child.
- If the data to be inserted is less than the current node's data, move to the left subtree.
	- If the left child of the current node is null, create a new node with the data and make it the left child.
	- otherwise, repeat the process recursively with the left child.

### Time and Auxiliary Space Complexity

- **Time Complexity**: In the worst case, when the tree is highly unbalanced and resembles a linked list, the time complexity for insertion is `O(n)`, where `n` is the number of nodes in the tree. However, in a well-balanced BST, the time complexity is `O(log n)` on average.

- **Auxiliary Space Complexity**: The space complexity is `O(h)`, where `h` is the height of the tree. In the worst case (highly unbalanced tree), it can be `O(n)`, and in the best case (well-balanced tree), it's `O(log n)`.

### Code (C++)

```cpp
class Solution {
public:
    Node* insert(Node* node, int data) {
        if (!node) 
            return new Node(data);
            
        if (data > node->data){
            if (!node->right) 
                node->right = new Node(data);
            else 
                insert(node->right, data);
        } else if (data < node->data){
            if (!node->left) 
                node->left = new Node(data);
            else 
                insert(node->left, data);
        }
        
        return node;     
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.