## 12. Duplicate subtree in Binary Tree

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

To check if a binary tree contains a duplicate subtree of size 2 or more. It does so by checking if there are any identical subtrees within the tree.

Here are the steps in my approach:
- The dupSub function does a level-order traversal of the binary tree using a queue to extract all the nodes.
- While traversing the tree, it identifies non-leaf nodes and stores them in the nodes vector.
- After collecting non-leaf nodes, it iterates through the nodes vector and compares each pair of nodes using the same function to check if they have the same structure and values. If a match is found, it returns true, indicating the presence of a duplicate subtree.
- If no duplicate subtree is found during the iteration, it returns false.


### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, where `N` is the number of nodes in the binary tree. This is because we visit each node once to calculate its height and check the balance condition.

- **Space Complexity**: The space complexity is `O(H)`, where `H` is the height of the binary tree. In the worst case, the space complexity is `O(N + H)` for a skewed tree, and in the best case, it is `O(N)` for a balanced tree. This space is used for the recursive call stack.

### Code (C++)

```cpp
bool same(Node * x, Node * y)
{
    if((x == nullptr) ^ (y == nullptr))
        return 0;
    if((x == nullptr) and (y == nullptr))
        return 1;
    if(x -> data != y -> data)
        return 0;

    return same(x -> left, y -> left) and same(x -> right, y -> right);
}

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root)
    {
        vector<Node *> nodes;

        queue<Node *> q;
        q.push(root);

        while(!q.empty()){
            Node * cur = q.front();
            q.pop();

            bool leaf = 1;

            if(cur -> left != nullptr)
            {
                q.push(cur -> left);
                leaf = 0;
            }
            if(cur -> right != nullptr)
            {
                q.push(cur -> right);
                leaf = 0;
            }

            if(!leaf)
                nodes.push_back(cur);
        }

        for(int i = 0; i < nodes.size(); i++)
        {
            for(int j = i + 1; j < nodes.size(); j++)
            {
                if(same(nodes[i], nodes[j]))
                    return 1;
            }
        }

        return 0;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
