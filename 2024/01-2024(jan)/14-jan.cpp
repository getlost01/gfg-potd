//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {
public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        unordered_map<string, int> mp;
        vector<int> out;

        for (int i = 0; i < matrix.size(); i++) {
            string str;
            for (int j = 0; j < matrix[0].size(); j++)
                str.push_back(matrix[i][j] ? '1' : '0');

            if (mp.find(str) != mp.end()) 
                out.push_back(i);
            else
                mp[str] = i;
        }

        return out;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends