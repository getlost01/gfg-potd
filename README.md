## GFG Problem Of The Day

### Today - 6 May 2024
### Que - Print all nodes that don't have sibling
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1)

### My Approach
- The function noSibling initializes a global vector vec to store the data of nodes that have no siblings.
- It calls the recursive function func to traverse the binary tree in an in-order manner and populate vec with the data of nodes that meet the criteria of having no sibling.
- Within func, if a node has no sibling, its data is pushed into vec.
- After traversal, if vec is empty, it means there are no nodes without siblings, so it adds -1 to vec.
- Finally, it sorts vec in ascending order (if there are elements other than -1) and returns it.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(NlogN)`, where `N` is the number of nodes in the tree.
- **Auxiliary Space Complexity**: `O(N)`, due to the recursive calls.

### Code (C++)
```cpp
vector<int>vec;

void func(Node* node)
{
    if (node)
    {
        func(node->left);
        if (node->left && !node->right)
            vec.push_back(node->left->data);
        else if (!node->left && node->right)
            vec.push_back(node->right->data);
        func(node->right);
    }
}

vector<int> noSibling(Node* node)
{
    vec.clear();
    func(node);
    if (vec.empty())
    {
        vec.push_back(-1);
        return vec;
    }
    sort(vec.begin(), vec.end());
    return vec;
}
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

