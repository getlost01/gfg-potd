## 21. Candy
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/candy/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach
- I use a two-pass approach to calculate the minimum number of candies required.
- First, I iterate from left to right, checking if the current rating is greater than the previous one. If true, I increment the count of candies for the current child.
- Next, I iterate from right to left, checking if the current rating is greater than the next one. If true, I update the count of candies for the current child to the maximum of its current value and the count from the right side.
- Finally, I iterate through the ratings again, adding the maximum count of candies for each child to the total.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(N) - We iterate through the ratings array three times.
- **Auxiliary Space Complexity**: O(N) - We use two additional arrays of size N for left and right.

### Code (C++)
```cpp
class Solution {
public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int> left(N, 1), right(N, 1);
        
        for (int i = 1; i < N; ++i)
            if (ratings[i] > ratings[i - 1])
                left[i] += left[i - 1];

        for (int i = N - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                right[i] += right[i + 1];

        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += max(left[i], right[i]);

        return sum;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.