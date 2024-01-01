//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends

int totalNodes(Node *root)
{
    if(!root)
        return 0;

    // Total nodes in left subtree + Total nodes in right subtree + 1(current node)
    return totalNodes(root->left) + totalNodes(root->right) + 1;
}

void modifiedInorder(Node* root, Node* &prev, int mid, int &i, bool isOddSize, float &out )
{
    if(!root)
        return;
    
    modifiedInorder(root->left, prev, mid, i, isOddSize, out );

    if(i == mid){
        if(isOddSize)
            out = root->data;
        else
            out = ((float)prev->data + (float)root->data)/2;
    }
    ++i;
    prev = root;

    modifiedInorder(root->right, prev, mid, i, isOddSize, out);
}

float findMedian(struct Node *root)
{
      int n = totalNodes(root);

      Node* prev = NULL;
      bool isOddSize = n%2;
      int mid = (n/2) + 1;
      int i = 1;
      float out = 0;

      modifiedInorder(root, prev, mid, i, isOddSize, out);
      
      return out;
}