## 23. Given a linked list of 0s, 1s and 2s, sort it.

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)

### My Approach

To segregate the linked list containing 0s, 1s, and 2s, I'll follow the following steps:

- Traverse the linked list and count the occurrences of 0s, 1s, and 2s using a vector `cnt`.
- Traverse the linked list again and replace the node data based on the count of 0s, 1s, and 2s.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`, where `N` is the number of nodes in the linked list.
- **Auxiliary Space Complexity** : `O(1)`, as we are using a fixed-size vector of length 3 to store the count of elements.

### Code (C++)

```cpp
class Solution
{
public:
    Node* segregate(Node* head)
    {
        vector<int> cnt(3, 0);
        Node* itr = head;

        // Count occurrences of 0s, 1s, and 2s
        while (itr)
        {
            ++cnt[itr->data];
            itr = itr->next;
        }

        int i = 0;
        itr = head;
        
        // Replace node data based on counts
        while (itr)
        {
            int c = 0;
            while (c < cnt[i])
            {
                itr->data = i;
                itr = itr->next;
                ++c;
            }
            ++i;
        }
        
        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.