## 06. Techfest and the Queue
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
The `primePowers` function is implemented to count the prime factors of a given number. The `sumOfPowers` function iterates from `a` to `b` and sum the total prime factors using the `primePowers` function.

### Time and Auxiliary Space Complexity

- **Time Complexity:** `O(b * sqrt(max_element))`, where max_element is the maximum number in the range [a, b].
- **Auxiliary Space Complexity:** `O(1)`

### Code (C++)
```cpp
class Solution {
public:
    int primePowers(int n)
    {
        int cnt = 0;
        for(int i = 2; i <= sqrt(n); i++)
        {
            while(n % i == 0)
            {
                cnt++;
                n = n / i;
            }
        }
        
        if(n > 1)
            cnt++;
        
        return cnt;
    }
    
    int sumOfPowers(int a, int b)
    {
        int cnt = 0;
        for(int i = a; i <= b; i++)
            cnt += primePowers(i);
        
        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
```