# GFG Problem Of The Day

## Today - 5 June 2023
### Que - Find the Closest Element in BST

[Question Link](https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1)

### My approach
- Simple. traversal in binary search tree and find min different key with relative to `K` .


### Code (c++)
```
class Solution
{
    public:

    void check(struct Node *node, int k, int &md,int &md_key)
    {
        if (node == NULL)
            return ;
     
        if (node->data == k)
        {
            md_key = k;
            return;
        }
     
        if (md > abs(node->data - k))
        {
            md = abs(node->data - k);
            md_key = node->data;
        }
     
        if (k < node->data)
            check(node->left, k, md, md_key);
        else
            check(node->right, k, md, md_key);
    }
     
    int minDiff(Node *root, int k)
    {
        int md = INT_MAX, md_key = -1;
        check(root, k, md, md_key);
     
        return abs(md_key-k);
    }
};
```