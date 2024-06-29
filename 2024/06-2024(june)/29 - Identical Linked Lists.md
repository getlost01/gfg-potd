## 29. Identical Linked Lists
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/identical-linked-lists/1)

### My Approach
- Initialize two pointers, head1 and head2, to the heads of the two linked lists.
- Iterate through both lists simultaneously:
  - Compare the data of the nodes pointed to by head1 and head2.
  - If the data in the current nodes are equal, move head1 and head2 to the next nodes.
  - If the data in the current nodes are not equal, return 0 (lists are not identical).
- After exiting the loop, check if either head1 or head2 is not NULL:
  - If either list is not fully traversed, return 0 (lists are not identical).
  - If both lists are fully traversed and all nodes matched, return 1 (lists are identical).

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, Where `N` is the length of the shorter linked list
- **Auxiliary Space Complexity**: `O(1)`, as the function uses a constant amount of extra space regardless of the input size

### Code (C++)

```cpp
bool areIdentical(struct Node *head1, struct Node *head2)
{
    while (head1!=NULL && head2!=NULL)
    {
        if (head1->data==head2->data)
        {
            head1=head1->next;
            head2=head2->next;
        }
        else return 0;
    }
    if (head1!=NULL || head2!=NULL)
        return 0;
    return 1;
}
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
