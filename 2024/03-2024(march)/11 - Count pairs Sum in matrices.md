## 11. Count pairs Sum in matrices
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1)

### My Approach
To solve this problem, I have used a two-pointer approach. 
- I initialize one pointer at the top-right corner of `mat1` and another pointer at the bottom-left corner of `mat2`.
- Then, we move these pointers inward while adjusting them based on the sum of the elements at their respective positions. 
- If the sum is equal to `x`, we increment the count and move both pointers inward. If the sum is greater than `x`, we decrement the right pointer, and if it's less than `x`, we increment the left pointer. 
- We repeat this process until both pointers meet or cross each other.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(n*n)`, where n is the size of the matrices. We traverse both matrices once using the two-pointer approach, resulting in linear time complexity.
- **Auxiliary Space Complexity** : O(1). We use only a constant amount of extra space for storing variables like `l`, `r`, `cnt`, etc.

### Code (C++)
```cpp
class Solution {
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        int sz = n * n;
        int l = 0, r = sz - 1;
        int cnt = 0;
        
        while (l < sz && r >= 0)
        {
            int sum = mat1[l / n][l % n] + mat2[r / n][r % n];
            
            if (sum == x) {
                l++;
                r--;
                ++cnt;
            }
            else if (sum > x)
                --r;
            else
                ++l;
        }
        
        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.