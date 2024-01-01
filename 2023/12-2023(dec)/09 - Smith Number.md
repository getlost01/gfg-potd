## 09. Smith Number
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/smith-number4132/1)

### My Approach
Simple appoach, go with the flow of question.
**Check if the number is prime:**
- If the number is prime, it cannot be a Smith Number, so I return 0.
**Calculate the sum of the digits of the prime factors:**
- I iterate over the prime factors of the number and calculate the sum of their digits.
If this sum is equal to the sum of the digits of the original number, then it's a Smith Number.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(sqrt(n) + log(n))` - The prime factorization has a time complexity of `O(sqrt(n))`, and calculating the sum of digits also takes `O(log(n))` time.
- **Auxiliary Space Complexity**: `O(1)` as we use a constant amount of space for variables.

### Code (C++)
```cpp
class Solution {
public:
    bool is_prime(int n){
        if(n == 1)
            return false;
        
        for(int i = 2; i <= sqrt(n); ++i)
            if(n % i == 0)
                return false;
        
        return true;
    }
    
    int sumOfDigits(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
  
    int sumOfPrimeFactor(int n){
        int f = 1;
        int sum = 0;
        while(n > 1){
            ++f;
            if(!is_prime(f))
                continue;
                
            while(n % f == 0){
                sum += sumOfDigits(f);
                n /= f;
            }
        }
        return sum;
    }
  
    int smithNum(int n) {
        if(is_prime(n))
            return 0;
        
        return sumOfPrimeFactor(n) == sumOfDigits(n);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.