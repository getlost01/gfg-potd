# GFG Problem Of The Day

## Today - 29 June 2023
### Que - Next Happy Number

[Question Link](https://practice.geeksforgeeks.org/problems/next-happy-number4538/1)


### My approach
- The given constraints prefer us to use a brute force approach, so I iterate through all possible `next numbers` that can be considered as`happy` and return the happy number which encounters first.
- The logic behind determining a happy number is straightforward as well: I calculate the `sum` of each `digit squared`and continue this process until the sum becomes a `single-digit` element. Through observation, it is evident that only `1` and `7` in the single-digit form are considered happy numbers. Consequently, I return a boolean answer indicating whether the given number is happy or not.

---

### Code (c++) 
```cpp

class Solution{
public:

    bool isHappy(int n) {
        // 7 & 1 are the only numbers which can be happy in single digit by observation
        if (n == 1 || n == 7) 
            return 1;
            
        int next, sum;
        next = sum = n;

        while (next > 9) {
            sum = 0;

            while (next > 0) {
                int digit = next % 10;
                next /= 10;
                sum += digit * digit;
            }

            if (sum == 1 || sum == 7)
                return 1;

            next = sum;
        }

        return 0;
    }

    int nextHappy(int n) {
        int nextNum = n + 1;

        while (isHappy(nextNum) != 1)
            nextNum++;

        return nextNum;
    }
    
};
```

---

### Contribution

I always encourage contributors to participate in the discussion forum for this repository. If you have a better solution or any queries related to the `Problem of the Day` solution, please feel free to join the discussion. By sharing your insights and ideas, we can collectively enhance our coding knowledge and problem-solving skills.

To access the discussion section and engage in conversations, please [click here](https://github.com/getlost01/gfg-potd/discussions). I look forward to hearing from you and bring up  a collaborative learning environment.

---

#### If you find my solutions helpful, I would appreciate your support by considering giving a `⭐ star` to this repository.

---

#### Visitors
![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)