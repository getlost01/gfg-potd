## 20. Modular Exponentiation for large numbers
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1)

### My Approach
- ans is initialized to 1 to store the final result.
- x is reduced modulo M to ensure it is within the range [0, M-1].
- While n (the exponent) is greater than 0, repeat the following steps:
- If n is odd (i.e., n % 2 == 1):
- Multiply ans by x and take modulo M.
- This ensures that any intermediate results do not exceed the limits.
- Halve n by right-shifting it by 1 bit (n >>= 1), which is equivalent to n = n / 2.
- Square x and take modulo M (x = (x * x) % M).
- This prepares x for the next iteration.
- After the loop completes (when n becomes 0), return ans as the result.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(logN)`
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)`.

### Code (C++)

```cpp
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int ans=1;
            x%=M;
            while (n>0)
            {
                if (n%2==1)
                    ans=(ans*x)%M;
                n>>=1;
                x=(x*x)%M;
            }
            return ans;
		}
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
