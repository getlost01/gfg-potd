//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends

class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        struct Node* even = odd;
        struct Node* revOdd = NULL;
        struct Node* itr = odd;
        while(itr){
            struct Node* nextItr = itr->next;
            if(nextItr){
                even->next = itr->next->next;
                if(even->next)
                even = even->next;
                nextItr->next = revOdd;
                revOdd = nextItr;
            }else
                break;
            itr = even;
        }
        even->next = revOdd;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends