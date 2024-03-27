//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int findShortestPath(vector<vector<int>> &mat){
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        
        vector<pair<int, int>> bombs;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == 0) 
                    bombs.push_back({i, j}); 
                    
        for(auto itr : bombs){
            for(int d = 0; d < 4; ++d){
                int x = itr.first + dx[d];
                int y = itr.second + dy[d];
                if(x >= 0 && y >= 0 && x < m && y < n)
                    mat[x][y] = 0;
            }
        }
        
        queue<pair<int,int>> q;
        for(int i = 0; i < m; ++i) 
            if(mat[i][0]){ 
                mat[i][0] = 0;
                q.push({i, 0});
            }
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(f.second == n-1) 
                    return ans;
                    
                for(int d = 0; d < 4; ++d){
                    int x = f.first + dx[d];
                    int y = f.second + dy[d];
                    if(x >= 0 && y >= 0 && x < m && y < n && mat[x][y]){
                        mat[x][y] = 0;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends