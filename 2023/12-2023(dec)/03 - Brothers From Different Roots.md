## 03. Brothers From Different Roots
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/brothers-from-different-root/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
This question is another apllication of BST property of inordere traversal. So for solving this,
- I use in-order traversals of both trees to obtain sorted arrays `t1` and `t2`. 
- Then, I iterate through these arrays with two pointers, comparing the sum of elements at the pointers with the target `x`. Based on the comparison, I adjust the pointers to find pairs that sum to `x`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N + M)`, where `N` and `M` are the numbers of nodes in the two trees.
- **Auxiliary Space Complexity**: `O(N + M)`, as we store in-order traversals in arrays.

### Code (C++)
```cpp
class Solution {
public:
    void inorder(Node* root, vector<int>& v) {
        if (root == NULL)
            return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        vector<int> t1, t2;

        inorder(root1, t1);
        inorder(root2, t2);

        int i = 0, j = t2.size() - 1;
        int out = 0;

        while (i < t1.size() && j >= 0) {
            int sum = t1[i] + t2[j];
            if (sum > x)
                --j;
            else if (sum < x)
                ++i;
            else {
                ++out;
                ++i;
                --j;
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.