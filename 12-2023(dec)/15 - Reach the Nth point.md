## 15. Reach the Nth point
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reach-the-nth-point5433/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
- Initialize num1 and num2 to 1 and mod to 1e9+7.
- Use a loop to iteratively calculate the nth term:
- Calculate a as the sum of num1 and num2 modulo mod.
- Update num1 and num2 with the values of num2 and a.
- Return the final value of num2, representing the nth term in the sequence.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` - The loop runs for n iterations.

- **Auxiliary Space Complexity**: `O(1)`

### Code (C++)
```cpp
class Solution
{
	public:
	int nthPoint(int n)
	{
	    long long a=1, b=1, mod=1e9+7;
	    for(int i=1;i<n;i++)
	    {
	        long long c=(a+b)%mod;
	        a=b;
	        b=c;
	    }
	    return b;
	}
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
