## 6. Reverse alternate nodes in Link List

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1)

### My Approach
In this problem, our task is to traverse all even nodes, pick their alternate nodes, reverse those alternate nodes, and then attach this reversed list to the original linked list, thus changing its structure. 

Here's the step-by-step approach I used:

- Initialize `even` and `revOdd` pointers to track alternative even and reversed nodes.
- Traverse the linked list with an `itr` pointer.
- For each pair where `itr` points to the first node and `itr->next` to the second:
   - Update `even->next` to skip the second node (`itr->next->next`) if it exists.
   - Move `even` to its new place.
   - Reverse the second node and link it to `revOdd`.
- Lastly, connect the reversed nodes in `revOdd` to the list's end.

### Time and Auxiliary Space Complexity
- **Time Complexity**: The algorithm traverses the entire linked list once, so the time complexity is `O(n)`, where `n` is the number of nodes in the linked list.
- **Auxiliary Space Complexity**: The algorithm uses a constant amount of extra space, so the auxiliary space complexity is `O(1)`.

### Code (C++)
```cpp
class Solution {
public:
    void rearrange(struct Node *odd)
    {
        struct Node* even = odd;
        struct Node* revOdd = NULL;
        struct Node* itr = odd;
        
        while(itr) {
            struct Node* nextItr = itr->next;
            
            if (nextItr) {
                even->next = itr->next->next;
                if (even->next)
                    even = even->next;
                nextItr->next = revOdd;
                revOdd = nextItr;
            } else {
                break;
            }
            itr = even;
        }
        
        even->next = revOdd;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.