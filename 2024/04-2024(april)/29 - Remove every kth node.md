## 29. Remove every kth node
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-every-kth-node/1)

### My Approach
- Traverse the linked list while keeping track of the count of nodes visited (a) and a counter b initialized to 1.
- At each step, check if b * K equals a. If it does, skip the current node and increment b.
- Otherwise, add the data of the current node to a vector.
- After traversing the entire linked list, if the vector is empty, return nullptr since all nodes need to be deleted.
- Otherwise, traverse the linked list again and replace the data of each node with the corresponding data from the vector until the end is reached.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`
- **Auxiliary Space Complexity** : `O(N)`

### Code (C++)

```cpp
class Solution {
    public:
    Node* deleteK(Node *head,int K)
    {
        vector<int>vec;
        Node* temp=head;
        int a=0, b=1;
        while (temp)
        {
            ++a;
            if (b*K==a)
            {
                b++;
                temp=temp->next;
                continue;
            }
            vec.push_back(temp->data);
            temp=temp->next;
        }
        if (vec.size()==0)
            return nullptr;
        temp=head;
        for (int i=0;i<vec.size();i++)
        {
            temp->data=vec[i];
            if (i==vec.size()-1)
                temp->next=nullptr;
            else temp=temp->next;
        }
        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
