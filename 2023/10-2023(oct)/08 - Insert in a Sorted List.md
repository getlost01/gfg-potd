## 8. Insert in a Sorted List
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1)

### My Approach
I'm implementing the `sortedInsert` function to insert a new node with the given data into a sorted linked list. 

The steps are as follows:

- Create a new node with the given data.
- Check if the data of the head node is greater than or equal to the new data. If so, insert the new node at the beginning and return thr updated head.
- Otherwise, traverse the linked list to find the position where the new node should be inserted. 
	- This is done by comparing the data of the current node with the new data.
- Insert the new node after the current node and update the pointers to maintain the sorted order.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this algorithm is `O(n)`, where n is the number of nodes in the linked list. 
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` since we are using a constant amount of extra space for creating a new node and a few temporary pointers.

### Code (C++)
```cpp
class Solution {
public:
    Node *sortedInsert(struct Node* head, int data) {
        struct Node * newNode =  new Node(data);
        if(head->data >= data){
            newNode->next = head;
            return newNode;
        }
        struct Node * itr = head;
        while(itr->next && itr->next->data < data){
            itr = itr->next;
        }
        newNode->next = itr->next;
        itr->next = newNode;
        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.