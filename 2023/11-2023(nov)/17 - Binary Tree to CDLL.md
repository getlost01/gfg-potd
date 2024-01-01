## 17. Binary Tree to CDLL
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

To change a Binary Tree into a Circular Doubly Linked List, we follow a simple approach: go through the tree in an inorder manner and transform the left pointer into the previous pointer, and the right pointer into the next pointer of the Doubly Linked List.
Here are the steps to implement this approach:
- Introduce two global variables, namely `head` and `tail`, to keep track of the doubly linked list.
- Create a custom `in-order` traversal function for moving through the tree.
- While traversing, create a new node for each tree node and connect it to the previous one, and by this constructing the doubly linked list.
- After completing the traversal, link the head and tail nodes to create a circular structure.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the binary tree.
- **Auxiliary Space Complexity**: `O(N)`, where `N` is the number of nodes in the binary tree.

### Code (C++)
```cpp
class Solution {
public:
    Node* head;
    Node* tail;

    void inorder(Node *root) {
        if (!root)
            return;

        inorder(root->left);
        
        Node* curr = new Node;
        curr->data = root->data;
        if (tail) {
            tail->right = curr;
            curr->left = tail;
        } else 
            head = curr;
        tail = curr;

        inorder(root->right);
    }

    Node *bTreeToCList(Node *root) {
        tail = head = NULL;

        inorder(root);

        head->left = tail;
        tail->right = head;

        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.