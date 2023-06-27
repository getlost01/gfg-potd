//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends

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
            } else 
                curr = curr->next;
        }
        return head;
    }

    struct Node* makeUnion(Node* head1, Node* head2) {
        Node* mergedList = merge(head1, head2);
        Node* sortedList = mergeSort(mergedList);
        
        return removeDuplicates(sortedList);
    }
};



//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends