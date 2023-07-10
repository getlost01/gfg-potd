## GFG Problem Of The Day

### 🎉 Announcement
I have created a Git Book that contains all previous editorials for my GFG-POTD solutions. You can visit **[here](https://gl01.gitbook.io/gfg-editorials/)** to access it and refer to my previous solutions. In the future, I intend to establish a contribution flow, where others can contribute their solutions to this Git Book. I would appreciate hearing your thoughts and views on this in the [discussion section](https://github.com/getlost01/gfg-potd/discussions).

----
### Today - 10 July 2023
### Que - Transpose of Matrix

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1)

### My Approach

The problem of transposing a matrix can be solved by using two index variables, i and j. We can iterate over `i` from `0 to n - 1` and `j` from `i to n - 1` to avoid unnecessary repetition.
- In each iteration, we swap the elements `mat[i][j]` with `mat[j][i]`, to get required transpose matrix.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)` since a nested loops run for n iterations, where `n` is the size of the matrix.
- **Auxiliary Space Complexity**: `O(1)` since these operations were performed in-place, meaning it does not require any additional space.

### Code (C++)

```cpp
class Solution
{   
    public:
    void transpose(vector<vector<int>>& mat, int n)
    { 
        for(int i = 0; i<n;++i){
            for(int j = i; j<n;++j){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};
```

### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.


![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
