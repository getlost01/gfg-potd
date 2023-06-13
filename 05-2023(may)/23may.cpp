class Solution{
  public:
    int till;
int it = 0;
    Node* constructBinaryTree(int pre[], int preMirror[], int n)
    {
        Node* head = new Node(pre[0]);
        till = (int)log2(n);
        Node* temp = head;
        stack<pair<Node*,int>>st;
        for(int i = 1;i<=till;++i){
            st.push({temp,i-1});
            temp->left = new Node(pre[i]);
            temp = temp->left;
        }
        it = till;
        while(!st.empty()){
            temp = st.top().first;
            int index = st.top().second+1;
            // cout<<temp->data<<" "<<index<<endl;; 
            st.pop();
            temp->right = new Node(pre[++it]);
            temp = temp->right;
            for(int i = index+1;i<=till;++i){
                st.push({temp,i-1});
                temp->left = new Node(pre[++it]);
                temp = temp->left;
            }
        }
        
        
        return head;
    }
};