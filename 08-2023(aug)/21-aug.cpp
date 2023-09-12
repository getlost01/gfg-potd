//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int dx[8]   = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
    int dy[8]   = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
    
    bool isValid(int &ii, int jj, int &n, int &m){
        return ii<n && ii>=0 && jj<m && jj>=0;
    }
    
    int Count(vector<vector<int> >& mat) {
        int cnt = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i<n;++i){
            for(int j = 0; j<m; ++j){
                if(mat[i][j]){
                    int c = 0;
                    for(int k = 0; k<8;++k){
                        int ii = dx[k] + i;
                        int jj = dy[k] + j;
                        if(isValid(ii, jj , n ,m) && mat[ii][jj] == 0)
                            ++c;
                    }
                    if(c && c%2 == 0)
                        ++cnt;
                }
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends