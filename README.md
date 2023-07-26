## GFG Problem Of The Day

### 🎉 Announcement
I have created a Git Book that contains all previous editorials for my GFG-POTD solutions. You can visit **[here](https://gl01.gitbook.io/gfg-editorials/)** to access it and refer to my previous solutions. In the future, I intend to establish a contribution flow, where others can contribute their solutions to this Git Book. I would appreciate hearing your thoughts and views on this in the [discussion section](https://github.com/getlost01/gfg-potd/discussions).

----
### Today - 26 July 2023
### Que - Kth Ancestor in a Tree

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1)

### My Approach

- To find the Kth ancestor of a node in a binary tree, I use a recursive function called `findAncestor`. This function traverses the tree while keeping track of the distance from the target node to the current node.
- When we find the target node, we return `k-1` as the remaining distance towards its ancestor. During the backtracking process, the function continuously updates the minimum distance encountered so far `newK` in the left and right subtrees.
- Once `newK` becomes zero, it indicates that we have reached the Kth ancestor. At this point, the data of the current node is stored in the variable `out`, which serves as our required output."

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the binary tree. In the worst case, we may have to visit all nodes to find the Kth ancestor.
- **Auxiliary Space Complexity**: `O(H)`, where `H` is the height of the binary tree. This space is used for the recursive call stack during the traversal.

### Code (C++)

```cpp
int out;
int findAncestor(Node *root, int k, int node){
    if(root -> data == node)
        return k-1;
    
    int newK = INT_MAX;
    if(root->left){
        newK = findAncestor(root->left,k,node);
    }
    if(root->right)
        newK = min(newK,findAncestor(root->right,k,node));
    
    if(newK == 0)
        out = root->data;
    
    return newK - 1;
}

int kthAncestor(Node *root, int k, int node)
{
    out = -1;
    findAncestor(root,k,node);
    return out;
}
```
### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.


![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
