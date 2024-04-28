## GFG Problem Of The Day

### Today - 28 April 2024
### Que - Delete Middle of Linked List
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1)

### My Approach
- Initialize a temporary pointer temp pointing to the head of the linked list and a variable count to 0.
- Traverse the linked list using a while loop until temp becomes nullptr.
- Increment the count variable for each node encountered.
- Check if count is less than or equal to 1, if true, return NULL indicating an empty or single-node list.
- Reset temp to point to the head of the list.
- Calculate the index of the middle node by dividing count by 2 and storing it in mid.
- Traverse the list again until mid - 1 becomes 0, updating temp to point to the middle node.
- Update the next pointer of the node before the middle node to skip the middle node, effectively removing it from the list.
- Return the head of the modified linked list.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`
- **Auxiliary Space Complexity** : `O(1)`

### Code (C++)

```cpp
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        Node* temp=head;
        int count=0;
        while (temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        if (count<=1)
            return NULL;
        temp=head;
        int mid=count/2;
        while(mid-1>0)
        {
            temp=temp->next;
            mid--;
        }
        temp->next=temp->next->next;
        return head;
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

