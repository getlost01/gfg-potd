class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if (!r1 && !r2) {
        return true;
    }

    if (r1 && r2 && r1->data == r2->data) {
        return isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }

    return false;
    }
};
