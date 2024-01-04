## 04. Find element occurring once when all others are present thrice
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
The idea is to use a bitwise counting algorithm. 
- We maintain an array `bits` of size 32 to store the count of set bits at each position for all the numbers in the array. 
- Then, we iterate through the array and update the `bits` array by counting the set bits for each number.
- Finally, we go through the `bits` array and construct the result by adding the bits where the count is not a multiple of 3.

### Time and Auxiliary Space Complexity
- **Time Complexity:** `O(N)`, where N is the length of the input array.
- **Auxiliary Space Complexity:** `O(1)` (as we use only a constant 32 size vector).

### Code (C++)
```cpp
class Solution {
  public:
    int singleElement(int arr[], int N) {
        vector<int> bits(32, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 32; j++) {
                bits[j] += arr[i] & 1;
                arr[i] >>= 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; i++)
            if (bits[i] % 3 != 0)
                ans += 1 << i;

        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.