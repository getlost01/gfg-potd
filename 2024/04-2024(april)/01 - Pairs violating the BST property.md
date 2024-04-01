## 01. Pairs violating the BST property
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1)

### My Approach
To solve this problem, I implemented an in-order traversal of the binary search tree (BST) to get the elements in sorted order. 
- Then, I used an ordered set (a data structure provided by the GNU C++ pb_ds library) to efficiently keep track of elements encountered so far and calculate the distance of each element from its expected position in a sorted array. 
- This distance represents the number of elements smaller than the current element that have been encountered so far but should appear after it in a sorted array, violating the BST property.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(n * log(n))`, where n is the number of nodes in the binary search tree.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(n)`, where n is the number of nodes in the binary search tree.

### Code (C++)
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
  vector<int> order;
  void InOrder(Node *root){
    if (!root)
      return;
      
    InOrder(root->left);
    order.push_back(root->data);
    InOrder(root->right);
  }
  int pairsViolatingBST(int n, Node *root)
  {
    InOrder(root);
    
    int cnt = 0;
    ordered_set st;
    for (int i = 0; i < n; ++i){
      int distance = i - st.order_of_key(order[i]);
      st.insert(order[i]);
      cnt += distance;
    }
    return cnt;
  }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.