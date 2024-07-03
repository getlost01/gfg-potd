## GFG Problem Of The Day

### Today - 3 July 2024
### Que - Remove all occurences of duplicates in a linked list
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1)

### My Approach
- Create an unordered map mp to count the occurrences of each value in the linked list.
- Traverse the linked list using a pointer temp and update the map with the count of each node's data.
- Create a dummy node that points to the head of the linked list. This helps in handling edge cases where the head node might need to be removed.
- Initialize a pointer prev to the dummy node.
- Reset temp to the head of the linked list.
- Traverse the linked list again using temp.
- For each node, check the count of its data in the map:
- If the count is greater than 1, it means the node is a duplicate, so update the next pointer of prev to skip the current node (temp).
- If the count is 1, move the prev pointer to the current node (temp).
- Move the temp pointer to the next node.
- Set new_head to the next of the dummy node.
- Delete the dummy node to free up memory.
- Return new_head, which is the head of the modified linked list with duplicates removed.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the linked list.
- **Auxiliary Space Complexity**: `O(N)`, where `N` is the number of nodes in the linked list.

### Code (C++)

```cpp
class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head)
    {
        unordered_map<int, int>mp;
        Node* temp=head;
        while (temp)
        {
            mp[temp->data]++;
            temp=temp->next;
        }
        Node* dummy=new Node(0);
        dummy->next=head;
        Node* prev=dummy;
        temp=head;
        while (temp)
        {
            if (mp[temp->data]>1)
                prev->next=temp->next;
            else prev=temp;
            temp=temp->next;
        }
        Node* new_head=dummy->next;
        delete dummy;
        return new_head;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

