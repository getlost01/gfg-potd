## 27. Union of Two Linked Lists

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1)

### My Approach

To find the union of two linked lists, I have used the following approach:

- Combine the heads of both lists into a single list.
- Apply merge sort to sort the linked list.
- Eliminate duplicate elements from the sorted list.

### Code (C++)

```cpp
class Solution {
public:
    Node* merge(Node* head1, Node* head2) {
        if (!head1)
            return head2;

        if (!head2)
            return head1;

        Node* smallerHead = NULL;

        if (head2->data > head1->data) {
            smallerHead = head1;
            smallerHead->next = merge(head1->next, head2);
        } else {
            smallerHead = head2;
            smallerHead->next = merge(head1, head2->next);
        }
        return smallerHead;
    }

    Node* mergeSort(Node* head) {
        if (!head || head->next == NULL)
            return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = slow->next;
        slow->next = NULL;

        Node* sortedFirstHead = mergeSort(head);
        Node* sortedSecondHead = mergeSort(secondHalf);

        return merge(sortedFirstHead, sortedSecondHead);
    }

    Node* removeDuplicates(Node* head) {
        Node* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->data == curr->next->data) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }

    struct Node* makeUnion(Node* head1, Node* head2) {
        Node* mergedList = merge(head1, head2);
        Node* sortedList = mergeSort(mergedList);

        return removeDuplicates(sortedList);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.