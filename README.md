## GFG Problem Of The Day

### Today - 13 September 2023
### Que - Largest number possible

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/largest-number-possible5028/1)

### My Approach

To find the largest number possible with `N `digits and a given sum `S`, I followed these steps:

- Check if it's impossible to create a number with the given N and S. 
	- If S is zero and N is greater than 1 or if the maximum possible sum of N single-digit numbers (9*N) is less than S, return "-1" because it's impossible.
- Initialize an empty string `out` to store the result.
- Loop N times to construct the number:
    - If S is greater than or equal to 9, add '9' to the `out` string and subtract 9 from S.
    - Otherwise, if S is not zero, add the remaining value of S as a string to the `out` string and set S to 0.
    - If S is zero, add '0' to the `out` string to fill the remaining digits.
- Return the `out` string as the largest number possible.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm runs in `O(N)` time because we iterate through the digits once.
- **Auxiliary Space Complexity**: The space complexity is `O(N)` because we store the result in the `out` string, which can have a maximum of `N` digits.

### Code (C++)

```cpp
class Solution {
public:
    int isPerfectNumber(long long n) {
        if (n == 1)
            return 0;
        long long sum = 1;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                sum += i;
                if (n / i != i)
                    sum += n / i;
            }
        }
        return out;
    }
};
```
### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.


![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
