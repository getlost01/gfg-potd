## 23. AVL Tree Insertion
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/avl-tree-insertion/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Recommendation
This is a pretty common Data Structures and Algorithms problem. I strongly recommend checking out [this article](https://www.programiz.com/dsa/avl-tree "this article") for a clearer understanding of AVL trees, left and right rotations, and the balancing factor.

Writing an editorial for such a lengthy code isn't feasible here. Please take a look at the article mentioned above for more insights.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(log N)`, where `N` is the number of nodes in the AVL tree.
- **Auxiliary Space Complexity**: `O(log N)`, for the recursive call stack.

### Code (C++)
```cpp
class Solution {
public:
    int height(Node * N) {
        if (!N)
            return 0;
        return N->height;
    }

    Node * rightRotate(Node * y) {
        Node * x = y->left;
        Node * T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node * leftRotate(Node * x) {
        Node * y = x->right;
        Node * T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node * N) {
        if (!N)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node * insertToAVL(Node * node, int key) {
        if (node == NULL)
            return (new Node(key));

        if (key < node->data)
            node->left = insertToAVL(node->left, key);
        else if (key > node->data)
            node->right = insertToAVL(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->data)
            return rightRotate(node);

        if (balance < -1 && key > node->right->data)
            return leftRotate(node);

        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.