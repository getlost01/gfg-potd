# GFG Problem Of The Day

## Today - 28 June 2023
### Que - Maximum Depth Of Binary Tree

[Question Link](https://practice.geeksforgeeks.org/problems/maximum-depth-of-binary-tree/1)


### My approach
- I use the Breadth-First Search (BFS) algorithm to traverse all levels of the tree.
- By incrementing a `height` variable during each level traversal, I am able to keep track of the number of levels in the tree. 
- Since BFS visits all levels of the tree, the count of levels represents the maximum height of the tree that we require.

---

### Code (c++) 
```cpp
class Solution {
public:
    int maxDepth(Node* root) {
        int height = 0;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            ++height;
            
            while (sz--) {
                auto frontNode = q.front();
                q.pop();
                
                if (frontNode->left)
                    q.push(frontNode->left);
                if (frontNode->right)
                    q.push(frontNode->right);
            }
        }
        
        return height;
    }
};
```

---

### Contribution

I always encourage contributors to participate in the discussion forum for this repository. If you have a better solution or any queries related to the `Problem of the Day` solution, please feel free to join the discussion. By sharing your insights and ideas, we can collectively enhance our coding knowledge and problem-solving skills.

To access the discussion section and engage in conversations, please [click here](https://github.com/getlost01/gfg-potd/discussions). I look forward to hearing from you and bring up  a collaborative learning environment.

---

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

---

#### Visitors
![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)