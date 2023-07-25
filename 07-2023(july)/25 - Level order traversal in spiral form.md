## 25. Level order traversal in spiral form

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1)

### My Approach

To determine the spiral order of a binary tree, I employ a queue to conduct a level-order traversal. 
- Starting from the root, I enqueue the elements of each level and subsequently process them individually. If left and right children exist, I enqueue them as well.
- During the traversal of all levels, I store all the elements in the `out` vector.
- Additionally, I utilize the `turn` variable to check for alternate values(0 or 1, if 1 means reverse to form spiral), and if necessary(turn == 1), I'll reverse the corresponding subpart of the array.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm visits each node once, and for each node, it performs constant time operations like pushing and popping from the queue. Thus, the time complexity is `O(N)`, where `N` is the number of nodes in the binary tree.
- **Auxiliary Space Complexity**: `O(W+N)`, where `N` is the number of nodes in the binary tree, and `W` is the maximum width of the binary tree (the number of nodes in the level having the most nodes). In the worst case, the queue can store all the nodes of the last level.

### Code (C++)

```cpp
vector<int> findSpiral(Node *root)
{
    vector<int> out;
    queue<Node*> q;
    q.push(root);
    
    int turn = 1;
    while(!q.empty()){
        int sz = q.size();
        int len = out.size();
        
        while(sz--){
            Node* front = q.front();
            out.push_back(front->data);
            q.pop();
            
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        
        if(turn)
            reverse(out.begin()+len, out.end());
        
        turn = (turn + 1)%2;
    }
    return out;
}
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.