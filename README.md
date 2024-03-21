## GFG Problem Of The Day

### Today - 21 March 2024
### Que - ZigZag Tree Traversal
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1)

### My Approach
- Initialize an empty vector ans to store the zigzag traversal result.
- Check if the root is null. If so, return the empty ans vector.
- Use a queue q to perform level order traversal.
- Start by pushing the root node into the queue.
- Initialize a boolean variable left to true to control the direction of traversal.
- While the queue is not empty :
  - Get the size of the queue to process nodes at the current level.
  - Create a temporary vector vec to store node values at the current level.
  - Iterate through the nodes at the current level.
    - Dequeue a node from the front of the queue.
    -  the index to insert the node value based on the traversal direction.
    - Store the node value at the determined index in vec.
    - If the dequeued node has left or right child, enqueue them.
  - Toggle the value of left to switch the direction for the next level.
  - Append the values stored in vec to the result vector ans.
- Return the result vector ans containing the zigzag traversal of the tree.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N)`, where N is the number of nodes in the binary tree.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N)`, where N is the maximum number of nodes at any level of the tree.

### Code (C++)
```cpp
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector<int>ans;
    vector <int> zigZagTraversal(Node* root)
    {
        if (root==nullptr)
            return ans;
        queue<Node*> q;
        q.push(root);
        bool left=true;
        while (!q.empty())
        {
            int size=q.size();
            vector<int>vec(size);
            for (int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                int ind=left ? i : (size-1-i);
                vec[ind]=temp->data;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            left=!left;
            ans.insert(ans.end(), vec.begin(), vec.end());
        }
        return ans;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

