## 20. Form a number divisible by 3 using array digits
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/form-a-number-divisible-by-3-using-array-digits0717/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

Through observation, we can derive that the sum of the digits in a number is divisible by 3 if and only if the sum of digits itself is divisible by 3.
- To form a number divisible by 3 using array digits, I calculate the sum of all array elements modulo 3. 
- If the sum is divisible by 3, I return true, indicating that it's possible to form a number divisible by 3 using the array digits.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of elements in the array. We iterate through the array once to calculate the sum.
- **Auxiliary Space Complexity**: `O(1)`, as we use a constant amount of space for the `sum` variable.

### Code (C++)
```cpp
class Solution {
public:
    int isPossible(int N, int arr[]) {
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i] % 3;
        return sum % 3 == 0;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.