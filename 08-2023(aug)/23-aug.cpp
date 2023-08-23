//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int dx[8]   = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
    int dy[8]   = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };

    bool canForm(vector<vector<char>>& grid, string& word,int& i ,int& j, int dir){
        int ii = i, jj = j;
        for(int k = 1; k < word.size(); ++k){
            ii = dx[dir] + ii;
            jj = dy[dir] + jj;
            if(ii < 0 || jj < 0 || ii >= grid.size() || jj >= grid[0].size() || grid[ii][jj] != word[k]){
                return false;
            }
        }
        
        return true;
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> out;
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    for(int i = 0; i<n;++i){
	        for(int j = 0; j<m;++j){
	            if(grid[i][j] == word[0]){
	                for(int dir = 0; dir<8;++dir){
	                    if(canForm(grid,word,i,j,dir)){
	                        out.push_back({i,j});
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    
	    return out;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends