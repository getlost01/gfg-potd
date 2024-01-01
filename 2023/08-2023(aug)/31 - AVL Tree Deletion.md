## 31. AVL Tree Deletion

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/avl-tree-deletion/1)

### My Approach

An AVL tree is a self-balancing binary search tree where each node contains additional data known as a balance factor, which can be either -1, 0, or +1.
To perform a node deletion operation in an AVL Tree, you can utilize the following set of functions.

#### Height Calculation and Balance Factor
I've implemented two helper functions:
- `height(struct Node* node)`: This function calculates the height of a given node in the AVL tree recursively.
- `getBalanceFactor(struct Node* node)`: This function calculates the balance factor of a node, which is the difference in heights of its left and right subtrees.

#### Left Rotation
I've implemented the `leftRotate(struct Node* root)` function, which performs a left rotation on the given root node to maintain the balance factor of the tree.

#### Right Rotation
I've implemented the `rightRotate(struct Node* root)` function, which performs a right rotation on the given root node to maintain the balance factor of the tree.

#### Finding Successor for Deletion
I've implemented the `successorInorder(struct Node* root)` function, which finds the in-order successor of a node to handle cases where a node with two children needs to be deleted.

#### Deleting a Node
I've implemented the `deleteNode(struct Node* root, int data)` function, which handles the deletion of a node from the AVL tree. It considers various cases based on the number of children the node has.

#### Rebalancing the Tree
After deletion, I check if the balance factor of the tree violates the AVL property (greater than `1` or less than `-1`). If it does, I perform rotations to rebalance the tree.

### Please take note:
I understand that this is one of the more challenging aspects of data structures and algorithms. Therefore, I highly recommend referring to [this blog](https://www.programiz.com/dsa/avl-tree) for a clearer understanding of AVL Trees and their deletion operations.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity for inserting, deleting, and searching in an AVL tree is `O(log N)`, where `N` is the number of nodes in the tree. This is because AVL trees are balanced, and the height of the tree is limited by `log N`.
- **Auxiliary Space Complexity**: The space complexity is `O(log N)` for a balanced AVL tree due to the recursive function calls on the stack during tree operations.

### Code (C++)
```cpp
int height(struct Node* node) {
    if (node == NULL) 
        return 0;

    return node->height;
}

int getBalanceFactor(struct Node* node) {
    if (node == NULL) 
        return 0;
        
    return height(node->left) - height(node->right);
}

struct Node* leftRotate(struct Node* root) {
    struct Node* newMid = root->right;
    struct Node* temp = newMid->left;

    newMid->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newMid->height = max(height(newMid->left), height(newMid->right)) + 1;

    return newMid;
}

struct Node* rightRotate(struct Node* root) {
    struct Node* newMid = root->left;
    struct Node* temp = newMid->right;

    newMid->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newMid->height = max(height(newMid->left), height(newMid->right)) + 1;

    return newMid;
}

struct Node* successorInorder(struct Node* root) {
    struct Node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (!root) 
        return root;

    if (data < root->data) 
        root->left = deleteNode(root->left, data);
        
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
        
    else {
        if (root->left == NULL && root->right == NULL) 
            return NULL;
        else if (root->left == NULL) 
            return root->right;
        else if (root->right == NULL) 
            return root->left;
        

        struct Node* successor = successorInorder(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }

    if (!root) 
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalanceFactor(root);

    if (balance <= 1 && balance >= -1)
        return root;

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0) 
        return leftRotate(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.