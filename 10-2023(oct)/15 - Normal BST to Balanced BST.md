## 15. Normal BST to Balanced BST
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
To convert a normal Binary Search Tree (BST) into a balanced BST, I follow these steps:

1. Perform an in-order traversal of the original BST and store the nodes in an array (`arr`) in sorted order.
2. Create a new BST from the sorted `arr` by selecting the middle element as the root node, and then recursively constructing left and right subtrees.
3. Return the new balanced BST.

### Time and Auxiliary Space Complexity

- *Time Complexity*: `O(N)`, where `N` is the number of nodes in the original BST. This is because both the in-order traversal and the creation of the balanced BST are linear operations.
- *Auxiliary Space Complexity*: `O(N)`, where `N` is the number of nodes in the original BST. The auxiliary space is used for the `arr` vector, which stores all the nodes during in-order traversal.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> arr;

    void inorder(Node* node) {
        if (!node)
            return;
        inorder(node->left);
        arr.push_back(node->data);
        inorder(node->right);
    }

    Node* createBST(int low, int high) {
        if (low > high)
            return NULL;

        int mid = (low + high) / 2;
        Node* root = new Node(arr[mid]);

        root->left = createBST(low, mid - 1);
        root->right = createBST(mid + 1, high);

        return root;
    }

    Node* buildBalancedTree(Node* root) {
        inorder(root);
        return createBST(0, arr.size() - 1);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.