## 7. Pairwise swap elements of a linked list

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1)

### My Approach
I will traverse the linked list in pairs and swap the data values of adjacent nodes to achieve the pairwise swapping. The steps are as follows:

- Check if `itr` has a next node. If not, return the head as no swaps are possible.
- Initialize an iterator `itr` to the head of the list.
- Update the `head` to point to the second node (`head = head->next`) since it will become the new head after swapping.
- Update the next pointers of `itr` and the second node to perform the swap.
- Continue swapping pairs of nodes until the end of the list or until there's only one node left.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)` where `N` is the number of nodes in the linked list. We visit each node once.
- **Auxiliary Space Complexity**: `O(1)` as we use a constant amount of extra space.

### Code (C++)
```cpp
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if(!head->next)
            return head;

        struct Node* itr = head;
        head = head->next;
        itr->next = head->next;
        head->next = itr;
        while(itr){
            struct Node* curr = itr->next;
            if(curr && curr->next){
                itr->next = curr->next;
                curr->next = itr->next->next;
                itr->next->next = curr;
            }else
                break;
            itr = itr->next->next;
        }
        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.