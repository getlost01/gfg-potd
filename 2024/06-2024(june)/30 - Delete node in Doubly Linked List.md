## 30. Delete node in Doubly Linked List
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1)

### My Approach
- Check if the list is empty:
  - If head_ref is nullptr, return nullptr.
- If the node to be deleted is the head (i.e., x == 1):
  - Store the current head node in temp.
  - Move temp to the next node.
  - Delete the current head node.
  - Set temp->prev to nullptr.
  - Return temp as the new head of the list.
- If the node to be deleted is not the head:
  - Initialize temp to head_ref.
  - Traverse the list to the xth node using a while loop.
  - Store the previous node (temp->prev) in tempprev.
  - If temp->next is not nullptr (i.e., the node to be deleted is not the last node):
    - Store the next node (temp->next) in tempnext.
    - Link tempprev->next to tempnext.
    - Link tempnext->prev to tempprev.
  - If temp->next is nullptr (i.e., the node to be deleted is the last node):
    - Set tempprev->next to nullptr.
  - Delete the node pointed to by temp.
  - Return head_ref.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(M)`, where `N` is the position x of the node to be deleted
- **Auxiliary Space Complexity**: `O(1)`, as the function uses a constant amount of extra space regardless of the input size.

### Code (C++)

```cpp
class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
        if (head_ref==nullptr)
            return nullptr;
        if (x==1)
        {
            Node* temp=head_ref;
            temp=temp->next;
            delete head_ref;
            temp->prev=nullptr;
            return temp;
        }
        Node* temp=head_ref;
        while (x>1)
        {
            temp=temp->next;
            x--;
        }
        Node* tempprev=nullptr;
        tempprev=temp->prev;
        if (temp->next!=nullptr)
        {
            Node* tempnext=nullptr;
            tempnext=temp->next;
            tempprev->next=tempnext;
            tempnext->prev=tempprev;
        }
        else tempprev->next=nullptr;
        delete temp;
        return head_ref;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
