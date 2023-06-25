# GFG Problem Of The Day

## Today - 25 June 2023
### Que - Unique rows in boolean matrix

[Question Link](https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1)


### My approach
- An intuitive approach is followed, where two rows are compared, and if any row is found to have duplicates, it is not included in the output vector.
- To achieve this and optimize the redundant row check, a `vis` vector is used to determine if a row is equal to any of the previous rows. If was a not unique, the row is skipped without further checking.


### Code (c++) 
```

class Solution
{
public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
    {
        vector<bool> vis(row, false); // Avoid redundant checks by examining the visited array for non-unique index values.
        vector<vector<int>> out;
        
        for (int i = 0; i < row; ++i) {
            if (vis[i]) // If we encounter the same row value, we continue.
                continue;
            
            vis[i] = true; // Mark the ith index as visited.
            vector<int> binArr(col);
            
            for (int j = 0; j < col; ++j) // Convert the unique row array into a vector.
                binArr[j] = M[i][j];
                
            out.push_back(binArr); // Push the unique row into the output vector.
            
            for (int j = i + 1; j < row; ++j) {
                bool isEqual = true;
                
                for (int k = 0; k < col; ++k) { // Logic to check for two equal rows.
                    if (M[i][k] != M[j][k]) {
                        isEqual = false;
                        break;
                    }
                }
                
                vis[j] = isEqual | vis[j]; // If we find that this row is not unique, mark it as visited.
            }
        }
        
        return out;
    }
};



```

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)