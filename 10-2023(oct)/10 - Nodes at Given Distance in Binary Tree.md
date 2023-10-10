## 10. Nodes at Given Distance in Binary Tree

### Problem Statement
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1)

### My Approach

The intuition for solving this problem involves using depth-first search (DFS) to first find the target node and then tracing the Kth distance from the target. Since it is a binary tree, we employ backtracking to find the Kth distance from the parent's side link.

Here is what I have done:

```python
Let's take an example tree:

              17    
            /     \
          20      15
        /     \
      8        22 
    /     \
  4        12 
 /   \     /    \
13   1    10    14

Target Node = 12
K = 3

-> The first step is to find the DFS path to the target node.

             [17]    
            /     \
         [20]      15
        /     \
     [8]        22 
    /    \
  4       [12] 
 /   \    /    \
13   1   10    14

-> Now backtrack the DFS path with decreasing Kth value.

             [17, 0]    
            /       \
         [20, 1]     15
        /        \
     [8, 2]      22 
    /      \
  4        [12, 3]
 /   \     /      \
13   1    10      14

-> The crucial part is that while backtracking, we know if we came from the left or right child. 
If we came from the left child, then find all the Kth distance children from the right of the current node using DFS, and vice versa.

             [17, 0]    
            /       \
         [20, 1]     15
        /        \
     [8, 2]     [22, 0] 
    /        \
  [4,1]         [12, 3]
 /     \        /      \
[13,0] [1,0]  [1,2] [14,2]

-> Hence, our required answer is {1, 13, 17, 22}
```

To achieve this, I followed these steps:

- Created a function `trace` that takes the current node and the remaining distance `k` as parameters. This function is used to trace nodes at distance `k` from the current node.
- In the `trace` function:
   - If `k` is less than 0 or the current node is null, return.
   - If `k` is 0, add the current node's data to the `out` vector and return.
- In the `findDist` function:
   - If the current node is null, return `INT_MIN` to indicate that the target node was not found.
   - If the current node's data matches the target node's data:
     - Call the `trace` function with the current node and `k` as parameters to find nodes at distance `k`.
     - Return `k - 1` to indicate that the target node has been found at distance `k`.
- Recursively search for the target node in the left and right subtrees:
   - If found in the left subtree, process accordingly and return the updated distance.
   - If found in the right subtree, process accordingly and return the updated distance.
- In the `KDistanceNodes` function:
   - Initialize an empty vector `out` to store the result.
   - Call the `findDist` function to find the target node and trace nodes at distance `k`.
   - Sort the `out` vector in ascending order.
   - Return the sorted `out` vector as the result."

### Time and Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(N)`, where `N` is the number of nodes in the binary tree. This is because we perform a single DFS traversal of the tree to find the target node and trace nodes at distance `k`. For sorting the `out` vector, we use the `sort` function, which has a time complexity of `O(NlogN)`.

- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(H)`, where `H` is the height of the binary tree. This space is used for the recursive call stack during the DFS traversal.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> out;
    
    void trace(Node* node, int k)
    {
        if (!node || k < 0)
            return;

        if (k == 0)
        {
            out.push_back(node->data);
            return;
        }

        trace(node->left, k - 1);
        trace(node->right, k - 1);
    }

    int findDist(Node* node, int target, int k)
    {
        if (!node)
            return INT_MIN;

        if (node->data == target)
        {
            trace(node, k);
            return k - 1;
        }

        int fromLeft = findDist(node->left, target, k);
        if (fromLeft != INT_MIN)
        {
            if (fromLeft == 0)
                out.push_back(node->data);
            else if (fromLeft > 0)
                trace(node->right, fromLeft - 1);

            return fromLeft - 1;
        }

        int fromRight = findDist(node->right, target, k);
        if (fromRight != INT_MIN)
        {
            if (fromRight == 0)
                out.push_back(node->data);
            else if (fromRight > 0)
                trace(node->left, fromRight - 1);

            return fromRight - 1;
        }

        return INT_MIN;
    }

    vector<int> KDistanceNodes(Node* root, int target, int k)
    {
        out = vector<int>(0);
        findDist(root, target, k);
        sort(out.begin(), out.end());
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.