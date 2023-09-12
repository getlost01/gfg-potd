//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    struct trip{
      int x,y,steps;
    };
    
    int dx[4]   = { -1 , 1 ,  0  , 0 };
    int dy[4]   = { 0  , 0 , -1  , 1 };
    
    bool isValid(int &nx,int &ny,int &n,int &m){
        return (nx >= 0 && nx < n && ny >= 0 && ny < m);
    }

    int shortestDistance(int n, int m, vector<vector<int>> a, int X, int Y) {
       queue<trip> q;
       vector<vector<bool>> vis(n, vector<bool>(m, 0));
       
       q.push({0, 0, 0});
       vis[0][0] = 1;
       int out = INT_MAX;
       
       while(!q.empty())
       {
           int x = q.front().x;
           int y = q.front().y;
           int steps = q.front().steps;
           q.pop();
           
           if(x == X && y == Y)
               out = min(out, steps);
               
           for(int i = 0; i < 4; ++i)
           {
               int nx = x + dx[i];
               int ny = y + dy[i];
               if(isValid(nx,ny,n,m) && a[nx][ny] && !vis[nx][ny])
               {
                   vis[nx][ny] = 1;
                   q.push({nx, ny, steps+1});
               }
           }
       }
       return (out == INT_MAX)?-1 : out;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends