## GFG Problem Of The Day

## 200 days done ✅
Hey, folks! Today marks my **200th** day of consistently sharing solutions on this GitHub repository. If any of my solutions, are helpful to you, please consider giving a `⭐ star` to this repo. Else, it's totally fine. I created this repo to keep me motivated and solve daily GeeksforGeeks problems consistently.

<img width="250" src="https://github.com/getlost01/gfg-potd/assets/79409258/d1ec8a9b-867e-4d83-9312-6ad2da813915">

---

### Today - 30 November 2023
### Que - Shortest path from 1 to n
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1)

### My Approach
This is a basic greedy problem. To solve it, I begin with a value `n` and try to reach `1`. I employ a while loop as long as `n` is greater than `1`:
- At each step, I either divide `n` by `3` if it's divisible by `3`, or subtract `1`.
- I repeat this procedure until `n` becomes `1`, keeping track of the number of steps.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(log n))` - The time complexity is logarithmic because in each step, the value of `n` is either divided by 3 or subtracted by 1.
- **Auxiliary Space Complexity**: `O(1)` - The algorithm uses a constant amount of space.

### Code (C++)
```cpp
class Solution {   
public:
    int minimumStep(int n) {
        int cnt = 0;
        while (n > 1) {
            if (n % 3 == 0)
                n /= 3;
            else
                n -= 1;
            ++cnt;
        }
        return cnt;
    }
};
```
### Contribution and Support

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

