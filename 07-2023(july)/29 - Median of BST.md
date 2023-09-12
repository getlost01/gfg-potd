## 29. Median of BST

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/median-of-bst/1)

### My Approach

LOL GFG made this question appear easy, but it is not that easy. Although the task itself seems straightforward – perform Inorder traversal to get a vector of elements and then find the median from that vector – the real challenge lies in achieving it with limited auxiliary space. We need to ensure the solution uses only `O(h)` auxiliary space (where h is the height of the tree), not `O(n)` (where n is the number of all nodes). So let's figure out the solution within the constraints.

**To find the median of a Binary Search Tree (BST)**

1. First, we calculate the total number of nodes in the BST using the `totalNodes` function, which is a simple recursive function that counts the number of nodes in the left subtree, right subtree, and the current node.

2. Next, we perform the modified inorder traversal using the `modifiedInorder` function. This function maintains a `prev` pointer to keep track of the previously visited node, an `i` variable to keep track of the current node's position, and an `out` variable to store the median.

3. During the inorder traversal, when we reach the `mid` position (the middle element for odd-sized trees or the left-middle element for even-sized trees), we calculate the median accordingly. If the total number of nodes is `odd`, the median is the value of the node at the mid position. Otherwise, for even-sized trees, the median can be found by taking the average of the values stored in the nodes at positions `mid` and `mid-1`. These positions refer to the current `root` node and the `prev` node, respectively.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of the `totalNodes` function is O(N), where `N` is the number of nodes in the BST. The `modifiedInorder` function takes `O(N)` time since we visit each node once. Therefore, the overall time complexity of the `findMedian` function is `O(N)`.

- **Auxiliary Space Complexity**: `O(H)`, where `H` is the height of the BST. This is because the `modifiedInorder` function uses recursive calls, and the maximum height of the function call stack is equal to the height of the BST.

### Code (C++)

```cpp
int totalNodes(Node *root)
{
    if(!root)
        return 0;
        
    return totalNodes(root->left) + totalNodes(root->right) + 1;
}

void modifiedInorder(Node* root, Node* &prev, int mid, int &i, bool isOddSize, float &out )
{
    if(!root)
        return;
    
    modifiedInorder(root->left, prev, mid, i, isOddSize, out );

    if(i == mid){
        if(isOddSize)
            out = root->data;
        else
            out = ((float)prev->data + (float)root->data)/2;
    }
    ++i;
    prev = root;

    modifiedInorder(root->right, prev, mid, i, isOddSize, out);
}

float findMedian(struct Node *root)
{
      int n = totalNodes(root);

      Node* prev = NULL;
      bool isOddSize = n%2;
      int mid = (n/2) + 1;
      int i = 1;
      float out = 0;

      modifiedInorder(root, prev, mid, i, isOddSize, out);
      
      return out;
}
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.