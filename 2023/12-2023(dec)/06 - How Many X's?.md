## 06. How Many X's?
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/how-many-xs4514/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
Simply go with the flow of question.
- I iterate through the numbers in the given range (`L` to `R`). For each number, 
- I count the occurrences of the digit `X` by using the `cntX` function. 
	- The function divides the number by 10 in each iteration and checks if the last digit is equal to `X`. If it is, I increment the count.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O((R-L) * log(R))`, where `log(R)` is the number of digits in R.
- **Auxiliary Space Complexity**: `O(1)`, as no extra space is used.

### Code (C++)
```cpp
class Solution {
public: 
    void cntX(int n, int& X, int& cnt){
        while(n){
            if(n % 10 == X)
                ++cnt;
            n /= 10;
        }
    }

    int countX(int L, int R, int X) {
        int cnt = 0;
        
        for(int i = L + 1; i < R; i++)
            cntX(i, X, cnt);

        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.