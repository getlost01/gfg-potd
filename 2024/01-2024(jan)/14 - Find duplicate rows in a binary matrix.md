## 14. Find duplicate rows in a binary matrix
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
1. We iterate through each row of the matrix.
2. For each row, we convert it into a string representation where `1` represents a set bit, and `0` represents an unset bit.
3. We check if the string representation is already present in our unordered_map.
4. If it is present, we add the current row index to the `output` vector.
5. If it is not present, we add the string representation to the unordered_map.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(M * N)`, where M is the number of rows and N is the number of columns in the matrix.

- **Auxiliary Space Complexity** : `O(M * N)` for the unordered_map, where M is the number of rows and N is the number of columns.

### Code (C++)
```cpp
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
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
```