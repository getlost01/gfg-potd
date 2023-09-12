//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends

class Solution {
public:
    bool isValid(int &num, int &i, int &j, int grid[N][N]) {
        for (int ii = 0; ii < 9; ii++) {
            if (grid[ii][j] == num) {
                return false;
            }
            if (grid[i][ii] == num) {
                return false;
            }
            if (grid[3 * (i / 3) + ii / 3][3 * (j / 3) + ii % 3] == num) {
                return false;
            }
        }
        return true;
    }

    bool SolveSudoku(int grid[N][N]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    for (int num = 1; num <= 9; ++num) {
                        if (isValid(num, i, j, grid)) {
                            grid[i][j] = num;
                            if (SolveSudoku(grid)) {
                                return true;
                            }
                            grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void printGrid(int grid[N][N]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) 
                cout << grid[i][j] << " ";
        }
    }
};




//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends