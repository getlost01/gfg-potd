## 13. Floor in BST

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/floor-in-bst/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

To find the greatest value node in the Binary Search Tree (BST) that is smaller than or equal to a given value x, you can follow these steps:

- Initialize a variable floorValue to -1. This variable will store the floor value as we traverse the BST.
- Start at the root of the BST.
- Traverse the BST while comparing the values of nodes with x and updating floorValue accordingly. Use the following rules:
- If the current node's data is equal to x, return x as the floor value because you've found an exact match.
- If the current node's data is less than x, update floorValue to the current node's data, as it's a potential floor value, and move to the right subtree because you are looking for a greater value.
- If the current node's data is greater than x, move to the left subtree because you are looking for a smaller value.
- Continue this process until you have traversed the entire BST.
- Return floorValue as the final result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this algorithm is `O(H)`, where `H` is the height of the BST. In the best case, when the tree is balanced, the height H is log(N). So, the time complexity can vary from `O(N)` in the worst case to `O(log(N))` in the best case.

- **Space Complexity**: The space complexity of this algorithm is `O(1)`

### Code (C++)

```cpp
class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int floorValue = -1;

        while (root != nullptr)
        {
            if (root->data == x)
            {
                return x;
            } 
            else if (root->data < x)
            {
                floorValue = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        return floorValue;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
