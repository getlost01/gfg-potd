//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int n,m,ws;
    bool valid(int i, int j){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    bool dfs(vector<vector<char>>& board,string word,int ii,int i,int j,vector<vector<bool>>& vis){
        if(!valid(i,j)) return false;
        if(ii>=ws){
            return true;
        }
        bool res = false;
        vis[i][j] = true;
        if(valid(i+1,j) && !vis[i+1][j] && board[i+1][j] == word[ii]){
           res = res || dfs(board,word,ii+1,i+1,j,vis);
        }else if(!res && valid(i-1,j) && !vis[i-1][j] && board[i-1][j] == word[ii]){
           res = res || dfs(board,word,ii+1,i-1,j,vis);
        }else if(!res && valid(i,j+1) && !vis[i][j+1] && board[i][j+1] == word[ii]){
           res = res || dfs(board,word,ii+1,i,j+1,vis);
        }else if(!res && valid(i,j-1) && !vis[i][j-1] && board[i][j-1] == word[ii]){
           res = res || dfs(board,word,ii+1,i,j-1,vis);
        }
        vis[i][j] = false;
        
        return res;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        bool result =false;
        n = board.size();
        m = board[0].size();
        ws = word.size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(auto i = 0;i<board.size();++i){
            for(auto j = 0;j<board[i].size();++j){
                if(word[0] == board[i][j]){
                    vis[i][j] = true;
                    if(dfs(board,word,1,i,j,vis)) return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends