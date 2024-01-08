//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends

class Solution {
public:
    struct Node *reverseList(Node *curr) {
        if (!curr || !(curr->next))
            return curr;
        auto res = reverseList(curr->next);
        curr->next->next = curr;
        curr->next = NULL;
        return res;
    }

    struct Node *mergeResult(Node *node1, Node *node2) {
        if (!node1)
            return reverseList(node2);
        if (!node2)
            return reverseList(node1);

        Node *curr = new Node;
        Node *head = curr;

        while (node1 && node2) {
            if (node1->data < node2->data) {
                curr->next = node1;
                node1 = node1->next;
            } else {
                curr->next = node2;
                node2 = node2->next;
            }
            curr = curr->next;
        }

        while (node1) {
            curr->next = node1;
            node1 = node1->next;
            curr = curr->next;
        }

        while (node2) {
            curr->next = node2;
            node2 = node2->next;
            curr = curr->next;
        }

        head = head->next;
        return reverseList(head);
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends